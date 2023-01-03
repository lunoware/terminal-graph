#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <chrono>

int main() {

    const int WIDTH = 200;
    const int HEIGHT = 50;
    int OFFSET_X = -10;
    int OFFSET_Y = -10;

    std::string str;
    
    int values[WIDTH]= {};

    while(true){
        str = "";

        for(int i = 1; i < WIDTH; i++){
            values[i-1] = values[i];
        }

        values[WIDTH-1] = (rand() % 40 + 1)-20; 

        for(int y = HEIGHT+OFFSET_Y; y > OFFSET_Y; y--){
            for(int x = OFFSET_X; x < WIDTH+OFFSET_X; x++){

                if(values[x-OFFSET_X]/2 == y){
                    str += '*';
                }else {
                    str += ' ';
                }
            
                // Axis and values
                if(x > OFFSET_X && y-OFFSET_Y-10 == -1 && x % 10 == 0){
                    std::string lx = std::to_string(x/10);
                    str = str.substr(0, str.size()-(lx.size()));
                    str += lx;
                }
                if(x-OFFSET_X-10 == -1 && y % 5 == 0){
                    std::string ly = std::to_string(y/5);
                    str = str.substr(0, str.size()-(ly.size()));
                    str += ly;
                }
                if(y-OFFSET_Y-10 == 0){
                    str = str.substr(0, str.size()-1);
                    str += '-';
                }
                if(x-OFFSET_X-10 == 0){
                    str = str.substr(0, str.size()-1);
                    str += '|';
                }
            }
            str += '\n';
        }
        
        write(1, str.c_str(),str.size()); 

        usleep(50000);
        system("clear");

                

    }


return 0;
}

