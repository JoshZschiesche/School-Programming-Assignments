#include "std_lib_facilities_4.h"

int main()
{
    try
    {
        int count; 
        int pos;
        int act_pos;
        char sletter;
        vector <string> words;
        string word;
        string twords;

        ifstream dict;
        dict.open("/usr/share/dict/words");

            if (dict.fail())
            {
                cerr << "File unable to open\n";
                return 2;
            }

            while (!dict.eof())
            {
                dict >> twords;
                words.push_back(twords);
            }

            dict.close();

            while(true)
            {
                cout << "Which letter position?\n";
                cin >> pos;
                act_pos = pos-1;
                count = 0;
				if (!cin)
				{
					break;
				}

                for (int i = 0; i < words.size(); ++i)
                {
                    word = words[i];

                    if (pos <= word.length())
                    {
                        sletter = word[act_pos];
                        tolower(sletter);
                        switch (sletter)
                        {
                            case 'a': case 'e': case 'i': case 'o': case 'u':
                            count++;
                        }
                    }
                }
				cout << count << " Words in the dictionary have a vowel in position " << pos << "\n";
            }
            
        }
        catch (exception& e)
        {
            cerr << e.what() << '\n';
            return 2;
        }
        catch (...)
        {
            cerr << "oops unknown exception!\n";
            return 2;
        }
}
