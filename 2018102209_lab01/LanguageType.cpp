#include "LanguageType.h"

LanguageType::LanguageType() :description(7), command(32), result(30)
{
	/*****DEFAULT COMMAND DESCRIPTION*****/
	description[0] = "\t--- ID -- Command ----- ";
	description[1] = "\t--- PlayList Command--- ";
	description[2] = "\t--- SingerList Command--- ";
	description[3] = "\t--- Play Command--- ";
	description[4] = "\t--- Equalizer Command--- ";
	description[5] = "\t--- Language Command--- ";
	description[6] = "\t--- Recommend Song Command--- ";
	
	/*****COMMAND LIST*****/
	command[1] = "\t   1 : Add Music";
	command[2] = "\t   2 : Delete Music";
	command[3] = "\t   3 : Replace Music";
	command[4] = "\t   4 : Search Music by ID";
	command[5] = "\t   5 : Search Music by Singer";
	command[6] = "\t   6 : Search Music by Genre";
	command[7] = "\t   7 : Print all on screen";
	command[8] = "\t   8 : Make empty list";
	command[9] = "\t   9 : Get from file";
	command[10] = "\t   10 : Put to file";
	command[11] = "\t   11 : Add Music to PlayList";
	command[12] = "\t   12 : Print PlayList's Music info";
	command[13] = "\t   13 : Delete PlayList Music By ID";
	command[14] = "\t   14 : Add Singer to SingerList";
	command[15] = "\t   15 : Add Song to SingerList";
	command[16] = "\t   16 : Searching Singer Using SingerList";
	command[17] = "\t   17 : Play Song in PlayList by inserted Count";
	command[18] = "\t   18 : Play Song in PlayList by Number of Played";
	command[19] = "\t   19 : Add Equalizer";
	command[20] = "\t   20 : Replace Equalizer";
	command[21] = "\t   21 : Delete Equalizer";
	command[22] = "\t   22 : Select Equalizer";
	command[23] = "\t   23 : Display All Equalizer";
	command[24] = "\t   24 : Display Current Equalizer";
	command[25] = "\t   25 : Read Language From File";
	command[26] = "\t   26 : Delete Language from list";
	command[27] = "\t   27 : Set Language from list";
	command[28] = "\t   28 : Display Language list";
	command[29] = "\t   29 : Recommend Song (Simple)";
	command[30] = "\t   30 : Add Recommend Song from list";
	command[31] = "\t Choose a Command--> ";
		/*int ReadLanguageFromFile();
	int DeleteLanguage();
	int SetCurLanguage();
	int DisplayLanguageList();*/
	command[0] = "\t   0 : Quit";


	result[LE] = "\tThe List is Empty.";
	result[LF] = "\tThe List is Full.";
	result[D] = "\tDeleted.";
	result[FD] = "\tFailed to delete.";
	result[Rp] = "\tReplaced.";
	result[FRp] = "\tFailed to replace.";
	result[FRt] = "\tFailed to retrieve";
	result[II] = "\tInvalid Input.";
	result[IF] = "<============ Item FOUND !==========>";
	result[INF] = "<======== ITEM Not Found!==========>";
	result[IG] = "\tInput Genre : ";
	result[SN] = "\tSinger Name : ";
	result[SASI] = "\tStart Adding Song Info";
	result[SNF] = "\tSinger Not Found. Start Adding Singer Info First.";
	result[N] = "\tName : ";
	result[A] = "\tAge : ";
	result[S] = "\tSex : ";
	result[SMF] = " (1 : Male, 2 : Female)";
	result[SI] = "\t===== Song Info =====";
	result[NP] = "\t=====Now Playing=====";
	result[EL] = "\tEqualizer List";
	result[SE] = "\tSelect Equalizer (-1, default, -2 : cancel) : ";
	result[ES] = "\tEqualizer has been set.";
	result[FN] = "\tFile Name : ";
	result[LL] = "\tLanguage List : ";
	result[SL_rc] = "\tSelect Language (-1, default, -2 : cancel) : ";
	result[LS] = "\tLanguage Has been set.";
	result[CP] = "\tContinue display on screen? (y/n) : ?";
	result[SN2] = "\tSelect Number : ";
	/*
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t   1 : Add Music" << endl;
		cout << "\t   2 : Delete Music" << endl;
		cout << "\t   3 : Replace Music" << endl;
		cout << "\t   4 : Search Music by ID" << endl;
		cout << "\t   5 : Search Music by Singer" << endl;
		cout << "\t   6 : Search Music by Genre" << endl;
		cout << "\t   7 : Print all on screen" << endl;
		cout << "\t   8 : Make empty list" << endl;
		cout << "\t   9 : Get from file" << endl;
		cout << "\t   10 : Put to file " << endl;
		cout << endl;
		cout << "\t---PlayList Command--- " << endl;
		//cout << "\t---ID -- Command ----- " << endl;
		cout << "\t   11 : Add Music to PlayList" << endl;
		cout << "\t   12 : Print PlayList's Music info " << endl;
		cout << "\t   13 : Delete PlayList Music By ID " << endl;
		cout << endl;
		//cout << "\t---LAB04 Command--- " << endl;
		cout << "\t---SingerList Command--- " <<endl;
		cout << "\t   14 : Add Singer to SingerList " << endl;
		cout << "\t   15 : Add Song to SingerList " << endl;
		cout << "\t   16 : Searching Singer Using SingerList " << endl;
		cout << endl;
		//cout << "\t---LAB05 Command--- " << endl;
		cout << "\t--- Play Command--- " << endl;
		cout << "\t   17 : Play Song in PlayList by inserted Count" << endl;
		cout << "\t   18 : Play Song in PlayList by Number of Played" << endl;
		cout << endl;
		//cout << "\t---Project01 Command--- " << endl;
		cout << "\t--- Equalizer Command--- " << endl;
		cout << "\t   19 : Add Equalizer " << endl;
		cout << "\t   20 : Replace Equalizer " << endl;
		cout << "\t   21 : Delete Equalizer" << endl;
		cout << "\t   22 : Select Equalizer" << endl;
		cout << "\t   23 : Display All Equalizer" << endl;
		cout << "\t   24 : Display Current Equalizer" << endl;
		cout << endl;

		cout << "\t ---GenreType Command--- " << endl;
		cout << "\t   25 : Add Song To GenreList" << endl;
		cout << "\t   26 : Delete Song From GenreList" << endl;
		cout << "\t   27 : Display Song Info In GenreList" << endl;

	*/
}

void LanguageType::PrintDescriptionList()
{
	for (int i = 0; i < description.GetMaxSize(); i++)
	{
		cout << this->description[i] << endl;
	}
}

void LanguageType::PrintCommandList()
{
	for (int i = 0; i < command.GetMaxSize(); i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintResultList()
{
	for (int i = 0; i < result.GetMaxSize(); i++)
	{
		cout << this->result[i] << endl;
	}
}

void LanguageType::PrintAll()
{
	PrintMusicCommand();
	cout << endl;
	PrintPlayListCommand();
	cout << endl;
	PrintSingerListCommand();
	cout << endl;
	PrintPlayCommand();
	cout << endl;
	PrintEqualizerCommand();
	cout << endl;
	PrintLanguageCommand();
	cout << endl;
	PrintRecommendCommand();
	cout << endl;
	PrintQuitCommand();
	cout << endl;
	PrintInputCommand();
}

void LanguageType::PrintMusicCommand()
{
	cout << this->description[0] << endl;
	for (int i = 1; i < 11; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintPlayListCommand()
{
	cout << this->description[1] << endl;
	for (int i = 11; i < 14; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintSingerListCommand()
{
	cout << this->description[2] << endl;
	for (int i = 14; i < 17; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintPlayCommand()
{
	cout << this->description[3] << endl;
	for (int i = 17; i < 19; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintEqualizerCommand()
{
	cout << this->description[4] << endl;
	for (int i = 19; i < 25; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintQuitCommand()
{
	cout << this->command[0] << endl;
}

void LanguageType::PrintLanguageCommand()
{
	cout << this->description[5] << endl;
	for (int i = 25; i < 29; i++)
	{
		cout << this->command[i] << endl;
	}
}

void LanguageType::PrintInputCommand()
{
	cout << this->command[31];
}

void LanguageType::PrintRecommendCommand()
{
	cout << this->description[RC] << endl;
	for (int i = 29; i < 31; i++)
	{
		cout << this->command[i] << endl;
	}

}

int LanguageType::ReadFromFile(string fileName)
{
	this->name = fileName.substr(0, fileName.size() - 4);
	ifstream fin(fileName);
	if (fin.is_open())
	{
		string line = "";
		while (!fin.eof())
		{
			getline(fin, line);
			if (line == "#description")
			{
				while (!fin.eof())
				{
					getline(fin, line);
					//라인 받았는데 #command나 #result나 #end면 break
					if (line == "#command" || line == "#result" || line == "#end")
					{
						break;
					}

					switch (stoi(line.substr(0, line.find("\t"))))
					{
					case LIST:
						this->SetDescription(LIST, line.substr(line.find("\t"), line.size() - 1));
						break;
					case PL:
						this->SetDescription(PL, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SL:
						this->SetDescription(SL, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SC:
						this->SetDescription(SC, line.substr(line.find("\t"), line.size() - 1));
						break;
					case EQ:
						this->SetDescription(EQ, line.substr(line.find("\t"), line.size() - 1));
						break;
					case LC:
						this->SetDescription(LC, line.substr(line.find("\t"), line.size() - 1));
						break;
					case RC:
						this->SetDescription(RC, line.substr(line.find("\t"), line.size() - 1));
						break;
					default:
						break;
					}
				}
			}

			if (line == "#command")
			{
				while (!fin.eof())
				{
					getline(fin, line);
					if (line == "#command" || line == "#result" || line == "#end")
					{
						break;
					}

					int index = stoi(line.substr(0, line.find("\t")));
					if (index < this->GetMaxSizeOfCommandList())
					{
						this->SetCommand(index, line.substr(line.find("\t"), line.size() - 1));
					}
				}
			}

			if (line == "#result")
			{
				while (!fin.eof())
				{
					getline(fin, line);
					//라인 받았는데 #command나 #result나 #end면 break
					if (line == "#command" || line == "#result" || line == "#end")
					{
						break;
					}

					switch (stoi(line.substr(0, line.find("\t"))))
					{
					case LE: // List Empty
						this->SetResult(LE, line.substr(line.find("\t"), line.size() - 1));
						break;
					case LF: // List Full
						this->SetResult(LF, line.substr(line.find("\t"), line.size() - 1));
						break;
					case D: // Deleted
						this->SetResult(D, line.substr(line.find("\t"), line.size() - 1));
						break;
					case FD: // Failed to Delete
						this->SetResult(FD, line.substr(line.find("\t"), line.size() - 1));
						break;
					case Rp: // Replaced
						this->SetResult(Rp, line.substr(line.find("\t"), line.size() - 1));
						break;
					case FRp: // Failed to Replace
						this->SetResult(FRp, line.substr(line.find("\t"), line.size() - 1));
						break;
					case FRt: // Failed to Retrieve
						this->SetResult(FRt, line.substr(line.find("\t"), line.size() - 1));
						break;
					case II: // Invalid Input
						this->SetResult(II, line.substr(line.find("\t"), line.size() - 1));
						break;
					case IF: // ITEM FOUND!
						this->SetResult(IF, line.substr(line.find("\t"), line.size() - 1));
						break;
					case INF: // ITEM NOT FOUND!
						this->SetResult(INF, line.substr(line.find("\t"), line.size() - 1));
						break;
					case IG: //Input Genre
						this->SetResult(IG, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SN: //Singer Name
						this->SetResult(SN, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SASI: //Start Adding Song Info
						this->SetResult(SASI, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SNF: //Singer Not Found. Start Adding Singer Info First
						this->SetResult(SNF, line.substr(line.find("\t"), line.size() - 1));
						break;
					case N: //Name
						this->SetResult(N, line.substr(line.find("\t"), line.size() - 1));
						break;
					case A: //Age
						this->SetResult(A, line.substr(line.find("\t"), line.size() - 1));
						break;
					case S: //Sex
						this->SetResult(S, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SMF: // (1: Male, 2: Female)
						this->SetResult(SMF, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SI: //Song Info
						this->SetResult(SI, line.substr(line.find("\t"), line.size() - 1));
						break;
					case NP: //Now Playing
						this->SetResult(NP, line.substr(line.find("\t"), line.size() - 1));
						break;
					case EL: //Equalizer List
						this->SetResult(EL, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SE: //Select Equalizer
						this->SetResult(SE, line.substr(line.find("\t"), line.size() - 1));
						break;
					case ES: //Equalizer has been Set
						this->SetResult(ES, line.substr(line.find("\t"), line.size() - 1));
						break;
					case FN: //File Name
						this->SetResult(FN, line.substr(line.find("\t"), line.size() - 1));
						break;
					case LL: //Language List
						this->SetResult(LL, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SL_rc: //Language List
						this->SetResult(SL_rc, line.substr(line.find("\t"), line.size() - 1));
						break;
					case LS:
						this->SetResult(LS, line.substr(line.find("\t"), line.size() - 1));
						break;
					case CP:
						this->SetResult(CP, line.substr(line.find("\t"), line.size() - 1));
						break;
					case SN2:
						this->SetResult(SN2, line.substr(line.find("\t"), line.size() - 1));
						break;
					default:
						break;
					}
				}
			}

			if (line == "#end")
			{
				break;
			}
		}
		fin.close();
		return 1;
	}
	else
	{
		cout << "failed to open" << endl;
		return 0;
	}
}

void LanguageType::SetDescription(int index, string inDes)
{
	this->description[index] = inDes;
}

void LanguageType::SetCommand(int index, string inCom)
{
	this->command[index] = inCom;
}

void LanguageType::SetResult(int index, string inRes)
{
	this->result[index] = inRes;
}

void LanguageType::SetName(string inName)
{
	this->name = inName;
}

string LanguageType::GetName()
{
	return this->name;
}

int LanguageType::GetMaxSizeOfDescriptionList()
{
	return this->description.GetMaxSize();
}

int LanguageType::GetMaxSizeOfCommandList()
{
	return this->command.GetMaxSize();
}

int LanguageType::GetMaxSizeOfResultList()
{
	return this->result.GetMaxSize();
}

LanguageType& LanguageType::operator=(const LanguageType& data)
{
	this->name = data.name;
	this->description = data.description;
	this->command = data.command;
	this->result = data.result;
	return *this;
}

bool LanguageType::operator==(LanguageType inData)
{
	if (this->name == inData.name)
		return true;
	else
		return false;
}

bool LanguageType::operator>(LanguageType inData)
{
	if (this->name > inData.name)
		return true;
	else
		return false;
}

bool LanguageType::operator<(LanguageType inData)
{
	if (this->name < inData.name)
		return true;
	else
		return false;
}

string LanguageType::operator[](int index)
{
	if (index < this->result.GetMaxSize())
	{
		string copy = this->result[index];
		return copy;
	}
	else
	{
		cout << "Index Error Detected." << endl;
		exit(1);
	}
}
