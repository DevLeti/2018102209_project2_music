#define CURL_STATICLIB
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Wldap32.lib")

#include "Application.h"
#include <iostream>
#include <string>
using namespace std;

Application::Application()
{
}

void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가
			AddMusic();
			break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제
			DeleteMusic();
			break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신
			ReplaceItem();
			break;
		case 4:		// 입력된 정보로 리스트에서 곡을 찾아서 화면에 출력
			RetrieveMusic();
			break;
		case 5:		// 입력된 가수 이름으로 리스트에서 곡을 찾아서 화면에 출력
			SearchBySingerOld();
			break;
		case 6:		// 입력된 장르로 리스트에서 곡을 찾아서 화면에 출력
			SearchByGenre();
			break;
		case 7:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			break;
		case 8: 		// 리스트에 입력된 모든 곡을 삭제
			MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 11: //PlayList에 노래 추가
			AddSongToPL();
			break;
		case 12: //PlayList에 들어있는 노래 반복 출력
			PlayInsertOrder();
			break;
		case 13: //PlayList에 있는 노래 삭제
			DeleteSongFrPL();
			break;
		case 14: //SingerList에 가수 추가
			AddSinger();
			break;
		case 15: //SingerType에 Singer추가.
			AddSong();
			break;
		case 16: //Singer 찾아서 그 Singer의 노래 정보 출력.
			SearchBySinger();
			break;
		case 17: //PlayList에 들어간 순서대로 노래 재생.
			PlayIOAddTime();
			break;
		case 18: //Play된 횟수순서로 노래 재생.
			PlayIOFreq();
			break;

			// Equalizer part
		case 19:
			AddNewEqualizer();
			break;
		case 20:
			ReplaceEqualizer();
			break;
		case 21:
			DeleteEqualizer();
			break;
		case 22:
			SetCurrentEqualizer();
			break;
		case 23:
			DisplayAllEqualizer();
			break;
		case 24:
			DisplayCurrentEqualizer();
			break;

			// Language Part
		case 25:
			ReadLanguageFromFile();
			break;
		case 26:
			DeleteLanguage();
			break;
		case 27:
			SetCurLanguage();
			break;
		case 28:
			DisplayLanguageList();
			break;

			// Recommend Part
		case 29:
			RecommendSongByKB();
			break;
		case 30:
			RecommendSongByList();
			break;
			
			
		case 0: //Quit
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	system("cls");
	int command;
	this->curLanguage.PrintAll();
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddMusic()
{
	if (this->MasterList.IsFull()) //List가 Full인 경우
	{
		cout << this->curLanguage[LF] << endl;
		//cout << "\tThe List is Full" << endl;
		return 0;
	}
	else
	{
		ItemType data;
		data.SetRecordFromKB();
		this->MasterList.Add(data);
		return 1;
	}
}

int Application::DeleteMusic()
{
	if (this->MasterList.IsEmpty()) // if list is empty
	{
		//cout << "\tThe List is Empty" << endl;
		cout << this->curLanguage[LE] << endl;
		return 0;
	}
	else
	{
		ItemType data;
		data.SetIdFromKB();
		if (this->MasterList.Delete(data))
		{	
			cout << this->curLanguage[D] << endl;
			//cout << "\tDeleted." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FD] << endl;
			//cout << "\tFailed to delete." << endl;
			return 0;
		}
	}
}

int Application::ReplaceMusic()
{
	if (this->MasterList.IsEmpty()) // if list is empty
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tThe List is Empty" << endl;
		return 0;
	}
	else
	{
		ItemType data;
		data.SetRecordFromKB();
		if (this->MasterList.Replace(data))
		{
			cout << this->curLanguage[Rp] << endl;
			//cout << "\tReplaced." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FRp] << endl;
			//cout << "\tFailed to replace." << endl;
			return 0;
		}
	}
}

int Application::RetrieveMusic()
{
	if (this->MasterList.IsEmpty()) // if list is empty
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tThe List is Empty" << endl;
		return 0;
	}
	else
	{
		ItemType data;
		data.SetIdFromKB();
		if (this->MasterList.Get(data) != 0)
		{
			cout << endl;
			data.DisplayRecordOnScreen();
			return 1;
		}
		else
		{
			if (data.GetGenre() != -1)
			{
				cout << endl;
				data.DisplayRecordOnScreen();
				return 1;
			}
			else
			{
				cout << this->curLanguage[FRt] << endl;
				//cout << "\tFailed to retrieve." << endl;
				return 0;
			}
		}
	}
	
	return 0;
}


void Application::DisplayAllMusic()
{
	this->MasterList.ResetList();
	ItemType Data;
	while (this->MasterList.GetNextItem(Data) != -1)
	{
		Data.DisplayRecordOnScreen();
	}
}

int Application::MakeEmpty()
{
	this->MasterList.MakeEmpty();
	return 1;
}

int Application::OpenInFile(char* fileName)
{
	this->m_InFile.open(fileName);
	if (this->m_InFile.is_open())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Application::OpenOutFile(char* fileName)
{
	this->m_OutFile.open(fileName);
	if (this->m_OutFile.is_open())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Application::SearchByID_BinaryS()
{
	ItemType item;
	item.SetIdFromKB(); //id입력받는다.

	if (MasterList.RetrieveByBS(item)) //0이 아니면(찾으면)
	{
		cout << this->curLanguage[IF] << endl;
		//cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << this->curLanguage[INF] << endl;
	//cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//실패(0)을 리턴
}

int Application::SearchByID_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id입력받는다.

	if (MasterList.Retrieve_SeqS(item)) //0이 아니면(찾으면)
	{
		cout << this->curLanguage[IF] << endl;
		//cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //해당 item을 출력한다.
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << this->curLanguage[INF] << endl;
	//cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//실패(0)을 리턴
}

int Application::SearchByGenre()
{
	int inGenre;

	cout << this->curLanguage[IG];
	//cout << "\tInput Genre : ";
	cin >> inGenre;

	this->MasterList.ResetList();
	ItemType nextItem;
	while (this->MasterList.GetNextItem(nextItem) != -1)
	{
		if (nextItem.GetGenre() == inGenre)
		{
			nextItem.DisplayRecordOnScreen();
		}
	}
	return 0;
}

int Application::AddSinger()
{
	SingerType item;
	item.SetRecordByKB();
	m_SingerList.Add(item);
	return 1;
}
int Application::AddSong()
{
	SingerType singer;
	ItemType song;

	string singerName;
	cout << this->curLanguage[SN];
	// cout << "\tSinger Name : ";
	cin >> singerName;

	singer.SetName(singerName);

	if (this->m_SingerList.Get(singer)) //found : 1, not found : 0
	{
		cout << this->curLanguage[SASI] << endl;
		//cout << "\tStart Adding Song Info" << endl;
		song.SetRecordFromKB();
		this->MasterList.Add(song);
		singer.Addsong(song.GetId());
		m_SingerList.Replace(singer);
	}
	else
	{
		cout << this->curLanguage[SNF] << endl;
		//cout << "\tSinger Not Found. Start Adding Singer Info First." << endl;
		this->AddSinger();
		this->m_SingerList.Get(singer);

		cout << this->curLanguage[SASI] << endl;
		//cout << "\tStart Adding Song Info" << endl;
		song.SetRecordFromKB();
		this->MasterList.Add(song);
		singer.Addsong(song.GetId());
		this->m_SingerList.Replace(singer);
	}
	return 0;
}

int Application::SearchBySinger()
{
	SingerType temp;

	string inName;
	cout << this->curLanguage[SN];
	//cout << "\tSinger Name : ";
	cin >> inName;

	temp.SetName(inName);
	if (m_SingerList.Get(temp)) // 1:Found, 0: Not Found
	{
		cout << this->curLanguage[N] << temp.GetName() << endl;
		cout << this->curLanguage[A] << temp.GetAge() << endl;
		cout << this->curLanguage[S] << temp.GetSex() << this->curLanguage[SMF]<<endl;
		/*
		cout << "\tName : " << temp.GetName() << endl;
		cout << "\tAge : " << temp.GetAge() << endl;
		cout << "\tSex : " << temp.GetSex() << " (1 : Male, 2 : Female)" <<endl;
		*/

		cout << this->curLanguage[SI] << endl;
		//cout << "\t===== Song Info =====" << endl;

		if (temp.GetSongList()->IsEmpty()) //if the Song List is Empty
		{
			cout << this->curLanguage[LE] << endl;
			//cout << "\tQueue is Empty." << endl;
			return 0;
		}

		ItemType data;
		temp.GetSongList()->ResetList();

		string itemName;
		int tempCurPointer = temp.GetSongList()->GetNextItem(itemName);

		while (true)
		{
			data.SetId(itemName);
			this->MasterList.RetrieveByBS(data);
			if (tempCurPointer == temp.GetSongList()->GetRear())
			{
				data.DisplayRecordOnScreen();
				break;
			}
			tempCurPointer = temp.GetSongList()->GetNextItem(itemName);
			data.DisplayRecordOnScreen();
		}
	}
	else
	{
		cout << this->curLanguage[FRt] << endl;
		//cout << "\tNot Found." << endl;
		return 0;
	}
}

int Application::PlayIOFreq()
{
	if (!this->m_PlayList.IsEmpty())
	{
		DoublyIterator<PlayItem> itor(this->m_PlayList); //iterator 생성
		itor.ResetList();

		PlayItem temp;
		temp = itor.Next(); //첫 element 가져오기.
		
		UnsortedList<PlayItem> tempList;
		int playCount = 0;
		while (tempList.GetLength() != this->m_PlayList.GetLength())
		{
			while (itor.NextNotNull())
			{
				if (temp.GetNumPlay() == playCount)
				{
					tempList.Add(temp);
				}
				temp = itor.Next();
			}
			itor.ResetList();
			temp = itor.Next();
			playCount++;
		}

		ItemType songData;
		tempList.ResetListToLast();

		while(tempList.GetPrevItem(temp) != -1)
		{
			songData.SetId(temp.GetID());
			
			cout << this->curLanguage[NP] << endl;
			//cout << "\t=====Now Playing=====" << endl;
			this->MasterList.Retrieve_SeqS(songData);
			songData.DisplayRecordOnScreen();
			temp.DisplayInTime();
			temp.DisplayNumPlay();
			temp.PlusNumPlay();
			this->m_PlayList.Replace(temp);
			cout << endl;
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tPlayList is Empty." << endl;
	}
	return 1;
}

int Application::AddNewEqualizer()
{
	if (!this->EqualizerList.IsFull())
	{
		EqualizerType inEqual;
		inEqual.SetRecordByKB();

		this->EqualizerList.Add(inEqual);
		return 1;
	}
	else
	{
		cout << this->curLanguage[LF] << endl;
		//cout << "\tList is Full." << endl;
	}
}

int Application::ReplaceEqualizer()
{
	if (!this->EqualizerList.IsEmpty())
	{
		EqualizerType inTemp;
		inTemp.SetNameByKB();

		if (this->EqualizerList.Get(inTemp))
		{
			inTemp.SetLowByKB();
			inTemp.SetMidByKB();
			inTemp.SetHighByKB();
			this->EqualizerList.Replace(inTemp);

			cout << this->curLanguage[Rp] << endl;
			//cout << "\t Equalizer information Replaced." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FRp] << endl;
			//cout << "\t Not Found." << endl;
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
	}
}

int Application::DeleteEqualizer()
{
	if (!this->EqualizerList.IsEmpty())
	{
		EqualizerType deleteTarget;
		deleteTarget.SetNameByKB();
		if (this->EqualizerList.Delete(deleteTarget))
		{
			cout << this->curLanguage[D] << endl;
			//cout << "\tDeleted." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FD] << endl;
			//cout << "\tEqualizer Not Found." << endl;
			return 0;
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
		return 0;
	}
}

int Application::SetCurrentEqualizer()
{
	if (!this->EqualizerList.IsEmpty())
	{
		EqualizerType temp;
		DoublyIterator<EqualizerType> itor(this->EqualizerList);
		temp = itor.Next();

		cout << this->curLanguage[EL] << endl;
		//cout << "\tEqualizer List" << endl;
		for (int i = 0; i < this->EqualizerList.GetLength(); i++)
		{
			cout << "\t--- " << i << " ---" << endl;
			temp.DisplayRecord();
			cout << endl;

			temp = itor.Next();
		}
		int select;

		cout << this->curLanguage[SE];
		//cout << "\tSelect Equalizer (-1, default, -2 : cancel) : ";
		cin >> select;
		while (select < -2 || select >(this->EqualizerList.GetLength() - 1)) // select < -1 또는 select > equalizer_length - 1 인 경우
		{
			cout << this->curLanguage[II] << endl;
			//cout << "\tInvalid Input." << endl;

			cout << this->curLanguage[SE];
			//cout << "\tSelect Equalizer (-1, default, -2 : cancel) : ";
			cin >> select;
		}

		if (select == -1) // default
		{
			EqualizerType reset;
			this->curEqualizer = reset;
			return 1;
		}
		else if (select == -2) // cancel
		{
			return 1;
		}
		else
		{
			itor.ResetList();
			temp = itor.Next();
			for (int i = 0; i < select; i++)
			{
				temp = itor.Next();
			}

			this->curEqualizer = temp;

			cout << this->curLanguage[ES] << endl;
			//cout << "\tEqualizer has been set." << endl;
			return 1;
		}

	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
		return 0;
	}
	
}

int Application::DisplayCurrentEqualizer()
{
	this->curEqualizer.DisplayRecord();
	return 1;
}

int Application::DisplayAllEqualizer()
{
	if (!this->EqualizerList.IsEmpty())
	{
		DoublyIterator<EqualizerType> itor(this->EqualizerList);
		EqualizerType temp = itor.Next();
		while (itor.NextNotNull())
		{
			temp.DisplayRecord();
			cout << endl;
			temp = itor.Next();
		}

		return 1;
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
		return 0;
	}
}

int Application::ReadLanguageFromFile()
{
	string fileName;

	cout << this->curLanguage[FN];
	//cout << "\tFileName : ";
	cin >> fileName;
	
	LanguageType addLang;
	if (addLang.ReadFromFile(fileName))
	{
		this->LanguageList.Add(addLang);
		return 1;
	}
	else
	{
		cout << this->curLanguage[FRt] << endl;
		//cout << "\tFailed to Retrieve." << endl;
		return 0;
	}
}

int Application::DeleteLanguage()
{
	if (!this->LanguageList.IsEmpty())
	{
		string inName;
		cout << this->curLanguage[N];
		//cout << "\tname : ";
		cin >> inName;

		LanguageType deleteTarget;
		deleteTarget.SetName(inName);

		if (this->LanguageList.Delete(deleteTarget))
		{
			cout << this->curLanguage[D] << endl;
			//cout << "\tdeleted." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FD] << endl;
			//cout << "\tFailed to Delete." << endl;
			return 0;
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tlist is empty." << endl;
		return 0;
	}
	
}

int Application::SetCurLanguage()
{
	if (!this->LanguageList.IsEmpty())
	{
		LanguageType temp;
		DoublyIterator<LanguageType> itor(this->LanguageList);
		temp = itor.Next();

		cout << this->curLanguage[LL] << endl;
		//cout << "\tLanguage List" << endl;
		for (int i = 0; i < this->LanguageList.GetLength(); i++)
		{
			cout << "\t--- " << i << " ---" << endl;
			cout << "\t" << temp.GetName() << endl;
			cout << endl;

			temp = itor.Next();
		}
		int select;

		cout << this->curLanguage[SL_rc]; cin >> select;

		while (select < -2 || select >(this->LanguageList.GetLength() - 1)) // select < -2 또는 select > Language_Length - 1 인 경우
		{
			cout << this->curLanguage[II] << endl;
			//cout << "\tInvalid Input." << endl;

			cout << this->curLanguage[SL_rc] << endl;
			//cout << "\tSelect Language (-1, default, -2 : cancel) : "; cin >> select;
		}

		if (select == -1) // default
		{
			LanguageType reset;
			this->curLanguage = reset;
			return 1;
		}
		else if (select == -2) // cancel
		{
			return 1;
		}
		else
		{
			itor.ResetList();
			temp = itor.Next();
			for (int i = 0; i < select; i++)
			{
				temp = itor.Next();
			}

			this->curLanguage = temp;

			cout << this->curLanguage[LS] << endl;
			//cout << "\tLanguage has been set." << endl;
			return 1;
		}

	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
		return 0;
	}
}

int Application::DisplayLanguageList()
{
	if (!this->LanguageList.IsEmpty())
	{
		DoublyIterator<LanguageType> itor(this->LanguageList);
		LanguageType temp = itor.Next();
		while (itor.NextNotNull())
		{
			cout << this->curLanguage[N] << temp.GetName();
			//cout << "\tName : " << temp.GetName();
			cout << endl;
			temp = itor.Next();
		}

		return 1;
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tList is Empty." << endl;
		return 0;
	}
}

/*****************GLOBAL FUNCTION FOR CURL******************/
size_t write_to_string(void* ptr, size_t size, size_t count, void* stream) {
	((string*)stream)->append((char*)ptr, 0, size * count);
	return size * count;
}
/***********************************************************/

string Application::RecommendSong(string inName)
{
	CURL* curl;
	CURLcode res;

	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL); // 이 옵션은 thread 메모리 공유에 안전하지 않다. 나는 주석처리함

	/* get a curl handle */
	curl = curl_easy_init();

	struct curl_slist* list = NULL;

	string readBuffer = "";

	if (curl) {
		// youtube recommend
		curl_easy_setopt(curl, CURLOPT_URL, "https://ox3hyvzxe9.execute-api.ap-northeast-2.amazonaws.com/v1/Youtube_Recommend"); //webserver ip 주소와 포트번호, flask 대상 router

		list = curl_slist_append(list, "Content-Type: application/json"); // content-type 정의 내용 list에 저장 
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list); // content-type 설정

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); // 값을 false 하면 에러가 떠서 공식 문서 참고함 
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L); // 값을 false 하면 에러가 떠서 공식 문서 참고함

		curl_easy_setopt(curl, CURLOPT_POST, 1L); //POST option

		string strResourceJSON = "{\"key\" : \"" + inName + "\"}";
		//string strResourceJSON = "{\"key\" : \"honne day 1\"}";

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strResourceJSON.c_str()); //string의 data라는 내용을 전송 할것이다
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 400);


		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl); // curl 실행 res는 curl 실행후 응답내용이 

		curl_slist_free_all(list); // CURLOPT_HTTPHEADER 와 세트

		replace(readBuffer.begin(), readBuffer.end(), '\"', (char)32);
		//cout << "result : "<< readBuffer << endl;

		/* Check for errors */
		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			readBuffer = "error";
		}
			

		/* always cleanup */
		curl_easy_cleanup(curl); // curl_easy_init 과 세트
	}
	curl_global_cleanup(); // curl_global_init 과 세트

	return readBuffer;
}

int Application::RecommendSongByKB()
{
	string inName;
	cout << this->curLanguage[N];

	cin.ignore(256, '\n');//clear buffer
	getline(cin, inName, '\n');
	
	string result = RecommendSong(inName);
	if (result == "error")
	{
		cout << this->curLanguage[FRt] << endl;
		return 0;
	}
	else
	{
		cout << this->curLanguage[N] << result << endl;
	}
}

int Application::RecommendSongByList()
{
	if (!this->MasterList.IsEmpty())
	{
		this->MasterList.ResetList(); // move curpointer to -1
		ItemType temp; // declare for display item in list

		//Display Items in list
		for (int i = 0; i < this->MasterList.GetLength(); i++)
		{
			this->MasterList.GetNextItem(temp);
			cout << "\t--- " << i << " ---" << endl;
			temp.DisplayNameOnScreen();
			cout << endl;
		}

		int index;
		cout << this->curLanguage[SN2];
		cin >> index;
		while (index < 0 || index > this->MasterList.GetLength() - 1) // if input index is out of range
		{
			//invalid input
			cout << this->curLanguage[II] << endl;

			//get input again
			cout << this->curLanguage[SN2];
			cin >> index;
		}

		//declare instance
		ItemType item;
		//get item by index
		this->MasterList.ResetList();
		for (int i = 0; i <= index; i++) // index를 받았으니까 조건문에 equal 붙여줘야 맞게 가져옴.
		{
			this->MasterList.GetNextItem(item);
		}

		string recommandSong = this->RecommendSong(item.GetName());
		item.SetName(recommandSong);


		cout << this->curLanguage[N] << item.GetName() << endl;
		item.SetTypeFromKB();
		item.SetGenreFromKB();
		item.SetComposerFromKB();
		item.SetSingerFromKB();
		item.SetIdFromKB();

		this->MasterList.Add(item);
		return 1;
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		return 0;
	}

	return 0;
}

int Application::PlayIOAddTime()
{
	if (!this->m_PlayList.IsEmpty())
	{
		DoublyIterator<PlayItem> itor(this->m_PlayList); //iterator 생성
		itor.ResetList();

		PlayItem song = itor.Next();
		PlayItem stopPoint = song;

		ItemType songData;
		songData.SetId(song.GetID());

		for (int i = 0; i < this->insertCount.GetInsertCount(); i++)
		{
			while (true)
			{
				if (i == song.GetInTime())
				{
					cout << this->curLanguage[NP] << endl;
					//cout << "\t=====Now Playing=====" << endl;
					this->MasterList.Retrieve_SeqS(songData);
					songData.DisplayRecordOnScreen();
					song.DisplayInTime();
					song.DisplayNumPlay();
					song.PlusNumPlay();
					this->m_PlayList.Replace(song);
					cout << endl;
					break;
				}

				song = itor.Next();
				if (!itor.NextNotNull())
				{
					itor.ResetList();
					song = itor.Next();
				}
				songData.SetId(song.GetID());
			}
			itor.ResetList();
			song = itor.Next();
		}
		return 1;

	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tPlayList is Empty." << endl;
		return 0;
	}
}

int Application::SearchBySingerOld()
{
	string inSinger;

	cout << this->curLanguage[N];
	//cout << "\tInput Singer : ";
	cin >> inSinger;

	this->MasterList.ResetList();
	ItemType nextItem;
	while (this->MasterList.GetNextItem(nextItem) != -1)
	{
		if (nextItem.GetSinger().find(inSinger) != string::npos)
		{
			nextItem.DisplayRecordOnScreen();
		}
	}
	return 0;
}

int Application::ReplaceItem()
{
	ItemType data;
	data.SetIdFromKB();

	MasterList.Get(data);
	if (data.GetGenre() != -1) //만약 정보가 불러졌다면 Genre가 -1이 아닐것
	{
		data.SetTypeFromKB();
		data.SetGenreFromKB();
		data.SetNameFromKB();
		data.SetComposerFromKB();
		data.SetSingerFromKB();

		if (this->MasterList.Replace(data)) // Replace Success
		{
			cout << this->curLanguage[Rp] << endl;
			//cout << "\tReplaced." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FRp] << endl;
			//cout << "\tFailed to replace." << endl;
			return 0;
		}
	}

	return 0;
}

int Application::AddSongToPL()
{
	ItemType searchResult;
	searchResult.SetIdFromKB();

	if (this->MasterList.Get(searchResult) != 0)
	{
		PlayItem inItem;
		inItem.SetItem(searchResult.GetId(), 0, this->insertCount.GetInsertCount());
		this->m_PlayList.Add(inItem);
		this->insertCount.PlusInsertCount();
		
		return 1;
	}
	else
	{
		PlayItem inItem;
		if (searchResult.GetName() != "")
		{
			inItem.SetItem(searchResult.GetId(), 0, this->insertCount.GetInsertCount());
			this->m_PlayList.Add(inItem);
			this->insertCount.PlusInsertCount();

			return 1;
		}
		
		//cout << "\tNot Found. Add Song to Master List First." << endl;
		ItemType item;
		item.SetRecordFromKB();
		this->MasterList.Add(item);

		inItem.SetItem(item.GetId(), 0, this->insertCount.GetInsertCount());
		this->m_PlayList.Add(inItem);

		this->insertCount.PlusInsertCount();

		return 1;
	}
}

void Application::PlayInsertOrder()
{
	if (!this->m_PlayList.IsEmpty())
	{
		//itor 만들어서 resetlist기능과 getnextitem기능 구현.
		DoublyIterator<PlayItem> itor(m_PlayList);
		itor.ResetList();//itor을 m_pFirst로.
		
		PlayItem item;
		ItemType info;
		bool print = true;
		char input;
		while (true)
		{
			input = '\0';
			item = itor.Next();
			if (!itor.NextNotNull()) //만약 m_pLast에 도착하면 true가 됨.
			{
				itor.ResetList();
				item = itor.Next();
			}
			info.SetId(item.GetID());
			this->MasterList.Retrieve_SeqS(info);
			info.DisplayRecordOnScreen();

			while (true)
			{
				cout << this->curLanguage[CP] << endl;
				//cout << "Continue display on screen? (y/n) : " << endl;
				cin >> input;
				if (input == 'y' || input == 'n')
				{
					break;
				}
				else
				{
					cout << this->curLanguage[II] << endl;
					//cout << "Invalid input..." << endl;
				}
			}

			if (input == 'n')
			{
				break;
			}
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tPlayList is Empty." << endl;
	}
}

int Application::DeleteSongFrPL()
{
	if (!this->m_PlayList.IsEmpty())
	{
		PlayItem target;
		string inID;
		cout << "\tID : " << endl;
		cin >> inID;
		target.SetID(inID);
		
		if (this->m_PlayList.Delete(target))
		{
			cout << this->curLanguage[D] << endl;
			//cout << "\tDeleted." << endl;
			return 1;
		}
		else
		{
			cout << this->curLanguage[FD] << endl;
			//cout << "\tFailed to delete." << endl;
			return 0;
		}
	}
	else
	{
		cout << this->curLanguage[LE] << endl;
		//cout << "\tPlayList is Empty." << endl;
		return 0;
	}
}

int Application::ReadDataFromFile()
{
	char fileName[1024];
	cout << this->curLanguage[FN];
	//cout << "\tEnter File Name : ";
	cin >> fileName;

	if (OpenInFile(fileName))
	{
		ItemType Data;
		while (!this->m_InFile.eof())
		{
			Data.ReadDataFromFile(this->m_InFile);
			this->MasterList.Add(Data);
		}
		this->m_InFile.close();

		return 1;
	}
	else
	{
		return 0;
	}
}

int Application::WriteDataToFile()
{
	char fileName[1024];
	cout << this->curLanguage[FN];
	//cout << "\tEnter File Name : ";
	cin >> fileName;

	if (this->OpenOutFile(fileName))
	{
		this->MasterList.ResetList();
		ItemType data;

		while (this->MasterList.GetNextItem(data) != -1)
		{
			data.WriteDataToFile(this->m_OutFile);
		}
		this->m_OutFile.close();

		return 1;
	}
	else // error
	{
		return 0;
	}
	return 0;
}