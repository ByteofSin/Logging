/** Title: Colors
 *	@version: v0.0.0.1
 *	@author: ByteofSin
 *	Contacts: 
 *		Email: ByteofSin@gmail.com 
 *	Created: 08/22/2022 
 *	Modified: 08/22/2022
 *	@brief: An enum class to represent various colors
 *	Externals: 
 *	@bug: none yet
 */

#ifndef BOS_LOGGING_COLORS_H    
#define BOS_LOGGING_COLORS_H

namespace byteofsin::logging {
    enum class Color {
        Blue,
        Green,
        Aqua,
        Red,
        Purple,
        Yellow,
        White,
        Gray,
        LightBlue,
        Black, 
        LightGreen,
        LightAqua,
        LightRed,
        LightPurple,
        LightYellow,
        BrightWhite
    };

     constexpr const char ColorToString(Color inputColor){
        switch (inputColor) {
            case Color::Blue: 
                return '1';
                break;
            case Color::Green: 
                return '2';
                break;
            case Color::Aqua: 
                return '3';
                break;
            case Color::Red: 
                return '4';
                break;
            case Color::Purple: 
                return '5';
                break;
            case Color::Yellow: 
                return '6';
                break;
            case Color::White: 
                return '7';
                break;
            case Color::Gray: 
                return '8';
                break;
            case Color::LightBlue: 
                return '9';
                break;
            case Color::Black: 
                return '0';
                break;
            case Color::LightGreen: 
                return 'A';
                break;
            case Color::LightAqua: 
                return 'B';
                break;
            case Color::LightRed: 
                return 'C';
                break;
            case Color::LightPurple: 
                return 'D';
                break;
            case Color::LightYellow: 
                return 'E';
                break;
            case Color::BrightWhite: 
                return 'F';
                break;
            default:
                return '0';
                break;

        }
    }

};


#endif