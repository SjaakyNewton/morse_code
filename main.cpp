#include "hwlib.hpp"

int main(){
    auto fuck_you_morse_code = "..-. ..- -.-. -.-/-.-- --- ..-";

    namespace target = hwlib::target;
    auto fucking_sound_thing = target::pin_out(target::pins::d8);
    int state = 1;
    
    for(const char * p = fuck_you_morse_code; state >= 0; p++){
        const char c = *p;
        if (c == '.') {
            fucking_sound_thing.write(1);
            hwlib::wait_ms(50);
            fucking_sound_thing.write(0);
        }
        else if(c == '-'){
            fucking_sound_thing.write(1);
            hwlib::wait_ms(150);
            fucking_sound_thing.write(0);
        }
        else if(c == ' '){
            hwlib::wait_ms(150);
        }
        else if(c == '/'){
            hwlib::wait_ms(350);
        }
        else if( c == '\0' ){
            state = -1;
        }
        else{
            hwlib::wait_ms(50);
        }
        hwlib::wait_ms(50);
    }
}