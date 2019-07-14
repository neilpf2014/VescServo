#ifndef _SERIALINPUT_H_
#define _SERIALINPUT_H_

#include <Arduino.h>
class SerialInput
{
    private:
        int BufferSz;
        char* buffer; // "string" buffer
        char* bufferHard; // "string" buffer for hardware serial
        int bi; // buffer index
        int biH;

        HardwareSerial* SerialHard = NULL;

    public:
        /**
		 * @brief      Class constructor
		 */
        SerialInput(void);
        SerialInput(int Sz);
        SerialInput(int Sz, HardwareSerial* port);

        /**
		 * @brief      initalize USB serial
         * @param      Sz - buffer size
		 */
        void initUSBserial(int Sz);

        /**
		 * @brief      initalize Hardware serial
         * @param      Sz - buffer size
		 */
        void initHardserial(int Sz);

        /**
		 * @brief      initalize Hardware serial
         * @param      port  - Reference to Serial port (pointer)
		 */
        void setHardSerial(HardwareSerial* port);

        /**
		 * @brief      read from USB serial, return string
		 */
        char* readUSBserial(void);

        /**
		 * @brief      read from hardware serial, return string
		 */
        char* readHardserial(void);
};

#endif