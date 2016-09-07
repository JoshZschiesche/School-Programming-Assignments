//Josh Zschiesche
//CSCE 121-502
//Due Octpber 18, 2015
//hw5pr4.cpp

#include "std_lib_facilities_4.h"

int main()
{
    try
    {
            while(cin)
            {
				ifstream dict;
				dict.open("/usr/share/dict/words");
				
                int count; 
                int pos;
                int act_pos;
                char sletter;
				vector <char> char_letters;
                string letters;
                string low; //short for letters of word
				char c;
				int word_count = 0;
                count = 0;

                cout << "Which letter position?\n";
                cin >> pos;
				act_pos = pos-1;
                cout << "Which letters would you like to check for in the position " << pos << "?\n" << "Also, please enter the letters together with no spaces, Example: to find the letters q, w, and e, simply type qwe\n";

                cin >> letters;
				
                for(int i = 0; i < letters.length(); ++i)
				{
					char_letters.push_back(letters[i]);
				}
				
                while(!dict.eof())
                {
                    string current_word;
                    dict >> current_word;
                    if (act_pos < current_word.size())
                    {
                        c = current_word[act_pos];
						for (char a: char_letters)
						{
							if (a == c)
							{
								count++;
								break;
							}
						}
                    }
                    
                }
				
				cout << "There are " << count << " words which have one of the letters [" << letters << "] In them at position " << pos << "\n";
				dict.close();
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

