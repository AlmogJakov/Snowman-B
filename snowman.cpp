#include <iostream>
using namespace std;
#include <array>
#include <stdexcept>
#include "snowman.hpp"

const int ten = 10;
const int eight = 8;
const int seven = 7;
const int six = 6;
const int five = 5;
const int four = 4;
const int three = 3;
const int two = 2;
const int one = 1;
const int zero = 0;

namespace ariel {
    bool left_hand_up = false;
    bool left_hand_down = false;
    bool right_hand_up = false;
    bool right_hand_down = false;
    // 1.a
    string sm_hat_no_left_hand(int a) {
        if (a==1) {return "_===_";}
        if (a==2) {return " ___\n.....";}
        if (a==3) {return "  _\n /_\\";}
        return " ___\n(_*_)";
    }
    // 1.b
    string sm_hat_left_hand(int a) {
        if (a==1) {return " _===_";}
        if (a==2) {return "  ___\n .....";}
        if (a==3) {return "   _\n  /_\\";}
        return "  ___\n (_*_)";
    }
    // 2
    string sm_nose_mouth(int a) {
        if (a==1) {return ",";}
        if (a==2) {return ".";}
        if (a==3) {return "_";}
        return " ";
    }
    // 3
    string sm_left_eye(int a) {
        if (a==1) {return ".";}
        if (a==2) {return "o";}
        if (a==3) {return "O";}
        return "-";
    }
    // 4
    string sm_right_eye(int a) {
        if (a==1) {return ".";}
        if (a==2) {return "o";}
        if (a==3) {return "O";}
        return "-";
    }
    // 5
    string sm_left_arm(int a) {
        // Global variables are maintained until the end of the program
        // therefore it is required to reset the variables obtained from a previous run.
        left_hand_up = false;
        left_hand_down = false;
        if (a==1) {
            left_hand_down = true;
            return "<";
        }
        if (a==2) {
            left_hand_up = true;
            return "\\";
        }
        if (a==3) {
            left_hand_down = true;
            return "/";
        }
        return "";
    }
    // 6
    string sm_right_arm(int a) {
        // Global variables are maintained until the end of the program
        // therefore it is required to reset the variables obtained from a previous run.
        right_hand_up = false;
        right_hand_down = false;
        if (a==1) {
            right_hand_down = true;
            return ">";
        }
        if (a==2) {
            right_hand_up = true;
            return "/";
        }
        if (a==3) {
            right_hand_down = true;
            return "\\";
        }
        return "";
    }
    // 7
    string sm_torso(int a) {
        if (a==1) {return " : ";}
        if (a==2) {return "] [";}
        if (a==3) {return "> <";}
        return "   ";
    }
    // 8
    string sm_base(int a) {
        if (a==1) {return " : ";}
        if (a==2) {return "\" \"";}
        if (a==3) {return "___";}
        return "   ";
    }

	string snowman(int a) {
        int check_len = to_string(a).length();
        // Negativity check & Invalid input length check.
        if (a < 0 || check_len != eight) {throw invalid_argument("invalid input");}
        // Digit range check.
        array<int, eight> arr = {};
        for (int i = seven; i >= 0; i--) {
            arr.at(i) = a % ten;
            a /= ten;
            if (arr.at(i) < 1 || arr.at(i) > 4) {throw invalid_argument("invalid input");}
        }
        // Build the snowman from below
        string base = sm_base(arr[seven]);
        string torso = sm_torso(arr[six]);
        string right_arm = sm_right_arm(arr[five]);
        string left_arm = sm_left_arm(arr[four]);
        string right_eye = sm_right_eye(arr[three]);
        string left_eye = sm_left_eye(arr[two]);
        string nose_mouth = sm_nose_mouth(arr[one]);
        string hat;
        // Get the hat according to the input of the hand.
        // [The hat may have 2 tiers so instead of chaining newline to second tier
        // it is preferable to build functions that return the hat according to
        // the left hand input].
        if (left_hand_down||left_hand_up) {hat = sm_hat_left_hand(arr[zero]);}
        else {hat = sm_hat_no_left_hand(arr[zero]);}
        torso = "("+torso+")";
        base = "("+base+")";
        // Build the head.
        string head = "("+left_eye+nose_mouth+right_eye+")";
        // Make a symmetry arrangement on the left.
        if (left_hand_up) {
            head = left_arm+head;
            base = " "+base;
            torso = " "+torso;
        } else if (left_hand_down) {
            torso = left_arm+torso;
            head = " "+head;
            base = " "+base;
        }
        if (right_hand_up) {head = head+right_arm;}
        else if (right_hand_down) {torso = torso+right_arm;}
        // Return result
        return hat+"\n"+head+"\n"+torso+"\n"+base;
    }
}