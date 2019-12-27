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
		case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�
			AddMusic();
			break;
		case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����
			DeleteMusic();
			break;
		case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����
			ReplaceItem();
			break;
		case 4:		// �Էµ� ������ ����Ʈ���� ���� ã�Ƽ� ȭ�鿡 ���
			RetrieveMusic();
			break;
		case 5:		// �Էµ� ���� �̸����� ����Ʈ���� ���� ã�Ƽ� ȭ�鿡 ���
			SearchBySingerOld();
			break;
		case 6:		// �Էµ� �帣�� ����Ʈ���� ���� ã�Ƽ� ȭ�鿡 ���
			SearchByGenre();
			break;
		case 7:		// ����Ʈ�� ����� ��� ���� ȭ�鿡 ���
			DisplayAllMusic();
			break;
		case 8: 		// ����Ʈ�� �Էµ� ��� ���� ����
			MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 11: //PlayList�� �뷡 �߰�
			AddSongToPL();
			break;
		case 12: //PlayList�� ����ִ� �뷡 �ݺ� ���
			PlayInsertOrder();
			break;
		case 13: //PlayList�� �ִ� �뷡 ����
			DeleteSongFrPL();
			break;
		case 14: //SingerList�� ���� �߰�
			AddSinger();
			break;
		case 15: //SingerType�� Singer�߰�.
			AddSong();
			break;
		case 16: //Singer ã�Ƽ� �� Singer�� �뷡 ���� ���.
			SearchBySinger();
			break;
		case 17: //PlayList�� �� ������� �뷡 ���.
			PlayIOAddTime();
			break;
		case 18: //Play�� Ƚ�������� �뷡 ���.
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
	if (this->MasterList.IsFull()) //List�� Full�� ���
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
	item.SetIdFromKB(); //id�Է¹޴´�.

	if (MasterList.RetrieveByBS(item)) //0�� �ƴϸ�(ã����)
	{
		cout << this->curLanguage[IF] << endl;
		//cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << this->curLanguage[INF] << endl;
	//cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
}

int Application::SearchByID_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id�Է¹޴´�.

	if (MasterList.Retrieve_SeqS(item)) //0�� �ƴϸ�(ã����)
	{
		cout << this->curLanguage[IF] << endl;
		//cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << this->curLanguage[INF] << endl;
	//cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
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
		DoublyIterator<PlayItem> itor(this->m_PlayList); //iterator ����
		itor.ResetList();

		PlayItem temp;
		temp = itor.Next(); //ù element ��������.
		
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
		while (select < -2 || select >(this->EqualizerList.GetLength() - 1)) // select < -1 �Ǵ� select > equalizer_length - 1 �� ���
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

		while (select < -2 || select >(this->LanguageList.GetLength() - 1)) // select < -2 �Ǵ� select > Language_Length - 1 �� ���
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
	curl_global_init(CURL_GLOBAL_ALL); // �� �ɼ��� thread �޸� ������ �������� �ʴ�. ���� �ּ�ó����

	/* get a curl handle */
	curl = curl_easy_init();

	struct curl_slist* list = NULL;

	string readBuffer = "";

	if (curl) {
		// youtube recommend
		curl_easy_setopt(curl, CURLOPT_URL, "https://ox3hyvzxe9.execute-api.ap-northeast-2.amazonaws.com/v1/Youtube_Recommend"); //webserver ip �ּҿ� ��Ʈ��ȣ, flask ��� router

		list = curl_slist_append(list, "Content-Type: application/json"); // content-type ���� ���� list�� ���� 
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list); // content-type ����

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); // ���� false �ϸ� ������ ���� ���� ���� ������ 
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L); // ���� false �ϸ� ������ ���� ���� ���� ������

		curl_easy_setopt(curl, CURLOPT_POST, 1L); //POST option

		string strResourceJSON = "{\"key\" : \"" + inName + "\"}";
		//string strResourceJSON = "{\"key\" : \"honne day 1\"}";

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strResourceJSON.c_str()); //string�� data��� ������ ���� �Ұ��̴�
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 400);


		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl); // curl ���� res�� curl ������ ���䳻���� 

		curl_slist_free_all(list); // CURLOPT_HTTPHEADER �� ��Ʈ

		replace(readBuffer.begin(), readBuffer.end(), '\"', (char)32);
		//cout << "result : "<< readBuffer << endl;

		/* Check for errors */
		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			readBuffer = "error";
		}
			

		/* always cleanup */
		curl_easy_cleanup(curl); // curl_easy_init �� ��Ʈ
	}
	curl_global_cleanup(); // curl_global_init �� ��Ʈ

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
		for (int i = 0; i <= index; i++) // index�� �޾����ϱ� ���ǹ��� equal �ٿ���� �°� ������.
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
		DoublyIterator<PlayItem> itor(this->m_PlayList); //iterator ����
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
	if (data.GetGenre() != -1) //���� ������ �ҷ����ٸ� Genre�� -1�� �ƴҰ�
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
		//itor ���� resetlist��ɰ� getnextitem��� ����.
		DoublyIterator<PlayItem> itor(m_PlayList);
		itor.ResetList();//itor�� m_pFirst��.
		
		PlayItem item;
		ItemType info;
		bool print = true;
		char input;
		while (true)
		{
			input = '\0';
			item = itor.Next();
			if (!itor.NextNotNull()) //���� m_pLast�� �����ϸ� true�� ��.
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