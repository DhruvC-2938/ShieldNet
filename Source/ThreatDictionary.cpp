#include "../Headers/ThreatDictionary.h"

ThreatDictionary::ThreatDictionary()
{
	root = new TrieNode();
}
void ThreatDictionary::insert(string word)
{
	TrieNode* current = root;

	for(int i = 0; i < word.length(); i++)
	{
		char ch = tolower(word[i]);

		int index = ch - 'a';

		if(index < 0 || index > 25)
		{
			continue;
		}

		if(current->children[index] == NULL)
		{
			current->children[index] = new TrieNode();
		}

		current = current->children[index];
	}

	current->isEndOfWord = true;
}
bool ThreatDictionary::search(string word)
{
	TrieNode* current = root;

	for(int i = 0; i < word.length(); i++)
	{
		char ch = tolower(word[i]);

		int index = ch - 'a';

		if(index < 0 || index > 25)
		{
			continue;
		}

		if(current->children[index] == NULL)
		{
			return false;
		}

		current = current->children[index];
	}

	return current->isEndOfWord;
}
void ThreatDictionary::loadSampleData()
{
	insert("hack");
	insert("trojan");
	insert("malware");
	insert("spyware");
	insert("phishing");
}
void ThreatDictionary::addSignature()
{
	string signature;

	cin.ignore(1000, '\n');

	cout << "\nEnter Signature: ";
	getline(cin, signature);

	insert(signature);

	cout << "Signature Added Successfully!\n";
}
void ThreatDictionary::searchSignature()
{
	string signature;

	cin.ignore(1000, '\n');

	cout << "\nEnter Signature To Search: ";
	getline(cin, signature);

	if(search(signature))
	{
		cout << "\nSignature Found!\n";
	}
	else
	{
		cout << "\nSignature Not Found!\n";
	}
}
void ThreatDictionary::checkTraffic()
{
	string traffic;

	cin.ignore(1000, '\n');

	cout << "\nEnter Traffic String: ";
	getline(cin, traffic);

	TrieNode* current = root;

	string matched = "";

	for(int i = 0; i < traffic.length(); i++)
	{
		char ch = tolower(traffic[i]);

		int index = ch - 'a';

		if(index < 0 || index > 25)
		{
			break;
		}

		if(current->children[index] == NULL)
		{
			break;
		}

		matched += ch;

		current = current->children[index];

		if(current->isEndOfWord)
		{
			cout << "\nThreat Signature Detected: "
				 << matched
				 << endl;

			return;
		}
	}

	cout << "\nNo Threat Signature Detected!\n";
}
void ThreatDictionary::displayWords(
	TrieNode* node,
	string currentWord)
{
	if(node->isEndOfWord)
	{
		cout << currentWord << endl;
	}

	for(int i = 0; i < 26; i++)
	{
		if(node->children[i] != NULL)
		{
			char ch = 'a' + i;

			displayWords(
				node->children[i],
				currentWord + ch);
		}
	}
}
void ThreatDictionary::displaySignatures()
{
	cout << "\n===== Threat Signatures =====\n";

	displayWords(root, "");
}
void ThreatDictionary::menu()
{
    int choice;

    do
    {
        cout << "\n===== Threat Dictionary =====\n";

        cout << "1. Add Signature\n";
        cout << "2. Search Signature\n";
        cout << "3. Check Traffic\n";
        cout << "4. Display Signatures\n";
        cout << "5. Back\n";

        cout << "\nEnter Choice: ";

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nPlease Enter A Number!\n";
            continue;
        }

        switch(choice)
        {
            case 1:
                addSignature();
                break;

            case 2:
                searchSignature();
                break;

            case 3:
                checkTraffic();
                break;

            case 4:
                displaySignatures();
                break;

            case 5:
                cout << "\nReturning To Main Menu...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}