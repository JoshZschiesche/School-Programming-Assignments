#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"
#include "std_lib_facilities_4.h"
#include "Point.h"
#include "find_solution.h"
#include "playerInfo.h"
#include <unistd.h>
#include <FL/Fl_Box.H>

struct sWindow;
int main();
int time_left = 7;
sWindow* wind;
struct sWindow : Graph_lib::Window{
    private:
        Image ii {Point{125,170}, "Pancakes.jpg"};
        bool button_pushed = false;

        vector <Button*> buttons;
        vector <Button*> swap_buttons;

        vector <playerInfo> players_scores;

        vector <Graph_lib::Ellipse*> ellipses;
        vector <Text*> texts;
        vector <Text*> more_texts;
		vector <Text*> hint_texts;
        vector <String> s;

        int number;
        int Cake_Pressed;
        int flips = 0;
        int score = 0;
		int min_flips = 0;
		int hints = 0;
		
		string string_flips = "";
		string string_flip_raw = "";
		string string_hint = "";
		
        In_box test;

        vector <int> *found_solution;

    public:
    sWindow(Point xy, int w, int h, const string& title) : Window(xy,w,h,title), test(Point(150,600), 200, 25, "Enter Initials")
    {
		wind = this;
        buttons.push_back(new Button(Point(50,50), 70, 20, "1", cb_n1));
        buttons.push_back(new Button(Point(50,100), 70, 20, "2", cb_n2));
        buttons.push_back(new Button(Point(50,150), 70, 20, "3", cb_n3));
        buttons.push_back(new Button(Point(50,200), 70, 20, "4", cb_n4));
        buttons.push_back(new Button(Point(50,250), 70, 20, "5", cb_n5));
        buttons.push_back(new Button(Point(50,300), 70, 20, "6", cb_n6));
        buttons.push_back(new Button(Point(50,350), 70, 20, "7", cb_n7));
        buttons.push_back(new Button(Point(50,400), 70, 20, "8", cb_n8));
        buttons.push_back(new Button(Point(50,450), 70, 20, "9", cb_n9));
        buttons.push_back(new Button(Point(50,500), 70, 20, "Quit", cb_q));
        buttons.push_back(new Button(Point(300,500), 100, 50, "Play Again", cb_again));
        buttons.push_back(new Button(Point(400,600), 90, 20, "Save Score", cb_save));
		buttons.push_back(new Button(Point(50,550), 70, 20, "Hint", cb_hint));

        attach_buttons();
        attach_pancake_image();
		
		hint_texts.push_back(new Text(Point(300,300), "Something That Should Never Appear"));

        swap_buttons.push_back(new Button(Point(500,50), 70, 20, "Pos: 1", cb_p1));
        swap_buttons.push_back(new Button(Point(500,100), 70, 20, "Pos: 2", cb_p2));
        swap_buttons.push_back(new Button(Point(500,150), 70, 20, "Pos: 3", cb_p3));
        swap_buttons.push_back(new Button(Point(500,200), 70, 20, "Pos: 4", cb_p4));
        swap_buttons.push_back(new Button(Point(500,250), 70, 20, "Pos: 5", cb_p5));
        swap_buttons.push_back(new Button(Point(500,300), 70, 20, "Pos: 6", cb_p6));
        swap_buttons.push_back(new Button(Point(500,350), 70, 20, "Pos: 7", cb_p7));
        swap_buttons.push_back(new Button(Point(500,400), 70, 20, "Pos: 8", cb_p8));
        swap_buttons.push_back(new Button(Point(500,450), 70, 20, "Pos: 9", cb_p9));

        texts.push_back(new Text(Point(300,50), "Team 34"));
        texts.push_back(new Text(Point(300,70), "Team Members:"));
        texts.push_back(new Text(Point(300,90), "Josh Zschiesche"));
        texts.push_back(new Text(Point(300,110), "Marc Sustantia"));
        texts.push_back(new Text(Point(300,130), "Madison Smith"));
        texts.push_back(new Text(Point(300,150), "Aldair Rosado"));
        texts.push_back(new Text(Point(200,400), "HOW TO PLAY:"));
        texts.push_back(new Text(Point(200,420), "1.) Click On A Button To Select The Level"));
        texts.push_back(new Text(Point(200,440), "2.) The Button You Click Will Determine"));
        texts.push_back(new Text(Point(224,460), "The Number Of Pancakes That Appear On The Screen"));
        texts.push_back(new Text(Point(200,480), "3.) Buttons Labeled 'Pos: X' Will Appear"));
        texts.push_back(new Text(Point(200,500), "4.) The Buttons 'Pos: X' Is In Reference To The Spatula Position"));
        texts.push_back(new Text(Point(200,520), "5.) If 'Pos X' Is Pressed, That Will Flip That Pancake And All Above It"));
        texts.push_back(new Text(Point(200,540), "6.) Example: *'Pos 4' is clicked* This flip the pancakes in position 4 to 1"));
        texts.push_back(new Text(Point(200,560), "7.) Quit The Game At Any Time By Pressing The 'Quit' Button"));
        texts.push_back(new Text(Point(250,480), "Press The 'Save Score' Button To Save Your Score"));
        texts.push_back(new Text(Point(250,580), "Press 'Play Again' To Play Again"));
        texts.push_back(new Text(Point(400,600), "Thank You Your Score Has Been Saved"));
        texts.push_back(new Text(Point(300,700), "INVALID INPUT"));

        attach_texts();
    }
	    vector <int> myvector;
        vector <int> control;
	////////////////CLOCK////////////////////////
		void CB_Clock() 
		{
			wind->is_end_of_game(wind->myvector, wind->control);
			{
				wind->detach_swap_buttons();
				//clear_ellipses();
				//attach(*buttons[10]);
				wind->detach_hint();
				wind->attach_INBOX();
				wind->detach_hint_text();
				wind->attach_save();
				wind->attach_save_text();
			}
			if (time_left > 0)
			{
				time_left=time_left-1;
				cerr << time_left << endl;
				wind->redraw();
				Fl::repeat_timeout(time_left,CB_time);
			}
			usleep(1000);
		}
	////////////////CLOCK////////////////////////
        void attach_buttons()
        {
            for(int i=0; i<10; ++i)
            {
                attach(*buttons[i]);
            }
        }
        void attach_texts()
        {
            for(int i=0; i<15; ++i)
            {
                attach(*texts[i]);
            }
        }
        void detach_texts()
        {
            for(int i=0; i<15; ++i)
            {
                detach(*texts[i]);
            }
        }
        void attach_save_text()
        {
            attach(*texts[15]);
            attach(*texts[16]);
        }
		bool is_end_of_game(vector<int> vector1, vector<int> vector2)
		{
			if(equal(vector1.begin(),vector1.end(),vector2.begin(),vector2.end()))
			{
				return true;
			}
			if(score == 0)
			{
				return true;
			}
			if(time_left <= 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
        void attach_save_message()
        {
            attach(*texts[17]);
        }
		/////////////////////TIMEOUT/////////////////////
		void set_time()
		{
			time_left = 10*number;
		}
		/////////////////////TIMEOUT////////////////////
        void detach_save_message()
        {
            detach(*texts[17]);
        }
        void detach_save_text()
        {
            detach(*texts[15]);
        }
        void detach_play_again_text()
        {
            detach(*texts[16]);
        }
        void attach_swap_buttons()
        {
            for(int i=0; i<number; ++i)
            {
                attach(*swap_buttons[i]);
            }
        }
        void detach_swap_buttons()
        {
            for(int i=0; i<number; ++i)
            {
                detach(*swap_buttons[i]);
            }
        }
        void detach_level_buttons()
        {
            for(int i=0; i<9; ++i)
            {
                detach(*buttons[i]);
            }
        }
        void attach_pancake_image()
        {
            attach(ii);
        }
        void detach_pancake_image()
        {
            detach(ii);
        }
        void swap_specefic_element()
        {
            int i1 = 0;
            int i2 = Cake_Pressed;
            while (i1 < i2)
            {
                swap(myvector[i1],myvector[i2]);
                ++i1;
                --i2;
            }
        }
        void makin_pancakes_makin_makin_pancakes()
        {
            for (int i=0; i<myvector.size();++i)
            {
                Graph_lib::Ellipse * e = new Graph_lib::Ellipse(Point(250,50*(i+1)),myvector[i]*20,10); //making the ellipses
                ellipses.push_back(e);
                e->set_fill_color(Color::yellow);
            }
        }
		void detach_hint_text() //should only be in the function is_end_of_game();
		{
			detach(*hint_texts[hints]);
		}
        void attach_pancakes()
        {
            for (int i=0; i < number; ++i)
            {
                attach(*ellipses[i]);
            }
        }
        void make_sure_not_same()
        {
            while(equal(myvector.begin(),myvector.end(),control.begin(),control.end()))
            {
                random_shuffle(myvector.begin(),myvector.end());
            }
        }
        void detach_pancakes()
        {
            for (int i=0; i < number; ++i)
            {
                detach(*ellipses[i]);
            }
        }
        void attach_cakes()
        {
            for (int i=0; i < Cake_Pressed; ++i)
            {
                attach(*ellipses[i]);
            }
        }
        void detach_cakes()
        {
            for (int i=0; i < Cake_Pressed; ++i)
            {
                detach(*ellipses[i]);
            }
        }
        void clear_ellipses()
        {
            ellipses.clear();
        }
        void calculate_score()
        {
            score = (100 - 10*(flips-min_flips))*number;
        }
        void attach_INBOX()
        {
            attach(test);
        }
        void detach_INBOX()
        {
            detach(test);
        }
        void attach_save()
        {
            attach(*buttons[11]);
        }
		void attach_b_done_in()
		{
			attach(*more_texts[0]);
		}
		void detach_b_done_in()
		{
			detach(*more_texts[0]);
		}
        void detach_save()
        {
            detach(*buttons[11]);
        }
        void clear_myvector()
        {
            myvector.clear();
        }
        void clear_control()
        {
            control.clear();
        }
		int get_min_flips()
		{
			return (*found_solution).size();
		}
		void set_flips()
		{
			flips = 0;
		}
		void attach_hint()
		{
			attach(*buttons[12]);
		}
		void detach_hint()
		{
			detach(*buttons[12]);
		}
		void assign_find_solution()
		{
			found_solution = find_solution(myvector);
			if (found_solution == nullptr)
			{
				error("failed to find solution");
			}
		}
		void minflip_to_string()
		{
			string_flips = to_string(min_flips);
		}
		void flips_to_string()
		{
			string_flip_raw = to_string(flips);
		}
		void make_can_b_done_in()
		{
			more_texts.push_back(new Text(Point(50,535), string_flips + " Is the Min Number Of Flips"));
		}
		void clear_more_texts()
		{
			more_texts.clear();
		}
        void Button1_Pressed(){
            number = 1;
			
			set_time();
			
            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button2_Pressed(){
            number = 2;
			set_time();
			//time_left =3;
			
			//Fl::add_timeout(1,CB_time);

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts(); 
			attach_hint();

            clear_ellipses(); 
            clear_myvector();
            clear_control();
			clear_more_texts();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();
			
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            /*for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }*/

            redraw();
        }
        void Button3_Pressed(){
            number = 3;
			
			set_time();
			//time_left =10;
			
			Fl::add_timeout(time_left,CB_time);
			
            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			
			cout << "Can be done in " << min_flips << "\n";

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button4_Pressed(){
            number = 4;
			
			set_time();
			
            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button5_Pressed(){
            number = 5;
			
			set_time();

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button6_Pressed(){
            number = 6;
			
			set_time();

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button7_Pressed(){
            number = 7;
			
			set_time();

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button8_Pressed(){
            number = 8;
			
			set_time();

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Button9_Pressed(){
            number = 9;
			
			set_time();

            attach_swap_buttons();
            detach_level_buttons();
            detach_pancake_image();
            detach_texts();
			attach_hint();
			clear_more_texts();

            clear_ellipses();
            clear_myvector();
            clear_control();

            for (int i=1; i<number+1; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
            for (int i=1; i<number+1; ++i) control.push_back(i); 

            random_shuffle(myvector.begin(),myvector.end());
            cout << "myvector contains:\n";

            make_sure_not_same();
			assign_find_solution();
			min_flips = get_min_flips();
			
			minflip_to_string();
			flips_to_string();
			
			cout << "Can be done in " << min_flips << "\n";
			make_can_b_done_in();
			attach_b_done_in();

            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();

            for (int i = 0; i < myvector.size(); ++i)
            {
                cout << ' ' << myvector[i] << "\n";
            }

            redraw();
        }
        void Quit_Pressed(){
            exit(0);
        }
        void yet_again(){
  
			set_flips();
			score = 0;
			hints = 0;
			time_left = 0;
			players_scores.clear();
            detach_save_message();
            detach_save_text();
            detach_INBOX();
            detach(*buttons[10]);
            detach_play_again_text();
            detach_pancakes();
            attach_texts();
            attach_buttons();
            attach_pancake_image();
            clear_ellipses();
            clear_myvector();
            clear_control();
            detach_save();
            for (int i = 0; i<5; i++)
            {
                detach(*texts[19+i]);
            }
            texts.erase(texts.begin()+19,texts.end());
            redraw();
        }
        void save_initials(){
            string s = test.get_string();
			detach_b_done_in();
            if (s.size() <= 3)
            {
                size_t found = s.find(" "); 
                if (found=string::npos)
                {
                attach(*buttons[10]);
                detach_save();
                detach_save_text();
                attach_save_message();
                detach(*texts[18]);
                detach(test);
                //score = 30;
                fstream scores;
                scores.open("Scores.txt");
                playerInfo newPlayer;
                vector<playerInfo> HighscoreTable (5);
                newPlayer.playerName = test.get_string();
                newPlayer.playerScore = score;
                for (int i = 0; HighscoreTable.size() > i; i++) {
                    scores >> HighscoreTable[i].playerName >> HighscoreTable[i].playerScore;
                }
                scores.close();
                HighscoreTable.push_back(newPlayer);
                sort(HighscoreTable.begin(), HighscoreTable.end(), player);
                scores.open("Scores.txt", ios::trunc | ios::out);
                for (int i = 0; HighscoreTable.size()-1 > i; i++) {
                    scores << HighscoreTable[i].playerName;
                    scores << " ";
                    scores << HighscoreTable[i].playerScore;
                    scores << endl;
                }
                HighscoreTable.erase(HighscoreTable.begin()+5);
                for (int i = 0; HighscoreTable.size() > i; i++)
                {
                    texts.push_back(new Text(Point(400, 620+(i*20)), "PLAYER:  " + HighscoreTable[i].playerName + "     " + "SCORE:  " + to_string(HighscoreTable[i].playerScore)));
                    attach(*texts[19+i]);
                }
                }
                else
                {
                    attach(*texts[18]);
                    redraw();
                    return;
                }
            }
            else
            {
                attach(*texts[18]);
                redraw();
                return;
            }
                

        }
		void give_hint()
		{
			detach(*hint_texts[hints]);
			cout << "\n" << (*found_solution)[0] << "\n";
			string_hint = to_string((*found_solution)[0]);
			hint_texts.push_back(new Text(Point(300,500), "Click 'Pos: " + string_hint + "'"));
			attach(*hint_texts[hints+1]);
			redraw();
			++hints;
		}
        /////////////////////////////////////////////////////////////////////////////////////////////
        void CakePosButton1_pressed(){
            Cake_Pressed = 0;
            cout << "\n";
            ++flips;
        }
        void CakePosButton2_pressed(){
            Cake_Pressed = 1;
            swap_specefic_element();

            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }
            cout << "\n";

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();

            ++flips;
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
                //clear_ellipses();
                //attach(*buttons[10]);
				detach_hint();
                attach_INBOX();
				detach_hint_text();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton3_pressed(){
            Cake_Pressed = 2;
            swap_specefic_element();

            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }
            cout << "\n";

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
                //clear_ellipses();
                //attach(*buttons[10]);
				detach_hint_text();
                attach_INBOX();
				detach_hint();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton4_pressed(){
            Cake_Pressed = 3;
            swap_specefic_element();

            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }

            cout << "\n";  

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
                //clear_ellipses();
                //attach(*buttons[10]);
				detach_hint_text();
                attach_INBOX();
				detach_hint();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton5_pressed(){
            Cake_Pressed = 4;
            swap_specefic_element();

            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }

            cout << "\n";

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
				detach_hint();
                //clear_ellipses();
                //attach(*buttons[10]);
                attach_INBOX();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton6_pressed(){
            Cake_Pressed = 5;
            swap_specefic_element();
            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }
            cout << "\n";

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
				detach_hint();
                //clear_ellipses();
                //attach(*buttons[10]);
                attach_INBOX();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton7_pressed(){
            Cake_Pressed = 6;
            swap_specefic_element();
            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }
            cout << "\n";

            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
				detach_hint();
                //clear_ellipses();
                //attach(*buttons[10]);
                attach_INBOX();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton8_pressed(){
            Cake_Pressed = 7;
            swap_specefic_element();
            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }

            cout <<  "\n";
            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
			
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
				detach_hint();
                //clear_ellipses();
                //attach(*buttons[10]);
                attach_INBOX();
                attach_save();
                attach_save_text();
            }
            redraw();
        }
        void CakePosButton9_pressed(){
            Cake_Pressed = 8;
            swap_specefic_element();
            for (int i=0; i<myvector.size(); ++i)
            {
                cout << myvector[i] << "\n";
            }

            cout << "\n";
            detach_pancakes();
            clear_ellipses();
            makin_pancakes_makin_makin_pancakes();
            attach_pancakes();
			assign_find_solution();
            ++flips;
			
			calculate_score();
			
			cout << "\n" << score << "\n";

            if (is_end_of_game(control,myvector)) 
            {
                detach_swap_buttons();
				detach_hint();
                //clear_ellipses();
                //attach(*buttons[10]);
                attach_INBOX();
                attach_save();
                attach_save_text();
            }
            redraw();
        }

        //////////////////////////////////////////////////////////////////////////////////////////////

        static void cb_n1(Address, Address pw){
            reference_to<sWindow>(pw).Button1_Pressed();
        }
        static void cb_n2(Address, Address pw){
            reference_to<sWindow>(pw).Button2_Pressed();
        }
        static void cb_n3(Address, Address pw){
            reference_to<sWindow>(pw).Button3_Pressed();
        }
        static void cb_n4(Address, Address pw){
            reference_to<sWindow>(pw).Button4_Pressed();
        }
        static void cb_n5(Address, Address pw){
            reference_to<sWindow>(pw).Button5_Pressed();
        }
        static void cb_n6(Address, Address pw){
            reference_to<sWindow>(pw).Button6_Pressed();
        }
        static void cb_n7(Address, Address pw){
            reference_to<sWindow>(pw).Button7_Pressed();
        }
        static void cb_n8(Address, Address pw){
            reference_to<sWindow>(pw).Button8_Pressed();
        }
        static void cb_n9(Address, Address pw){
            reference_to<sWindow>(pw).Button9_Pressed();
        }
        static void cb_q(Address, Address pw){
            reference_to<sWindow>(pw).Quit_Pressed();
        }
        static void cb_again(Address, Address pw){
            reference_to<sWindow>(pw).yet_again();
        }
        static void cb_save(Address, Address pw){
            reference_to<sWindow>(pw).save_initials();
        }
		static void cb_hint(Address, Address pw){
            reference_to<sWindow>(pw).give_hint();
        }
		static void CB_time(Address pw){
            reference_to<sWindow>(pw).CB_Clock();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        static void cb_p1(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton1_pressed();
        }
        static void cb_p2(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton2_pressed();
        }
        static void cb_p3(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton3_pressed();
        }
        static void cb_p4(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton4_pressed();
        }
        static void cb_p5(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton5_pressed();
        }
        static void cb_p6(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton6_pressed();
        }
        static void cb_p7(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton7_pressed();
        }
        static void cb_p8(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton8_pressed();
        }
        static void cb_p9(Address, Address pw){
            reference_to<sWindow>(pw).CakePosButton9_pressed();
        }
        int getnum()
        {
            return number;
        }
};
int main()
{
    sWindow win(Point{100,100}, 700,800, "Test");
    return gui_main();
}
