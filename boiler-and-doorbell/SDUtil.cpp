#include "SDUtil.h"

File root;

void SDInit()
{
    Serial.println("SD Init");
    if (!SD.begin(SD_CARD_CSPIN))
    {
        Serial.println("fail");
        while (1)
            ;
    }
}

// https://www.arduino.cc/en/Tutorial/listfiles
void printDirectory(File dir, int numTabs)
{
    while (true)
    {

        File entry = dir.openNextFile();
        if (!entry)
        {
            // no more files
            break;
        }
        for (uint8_t i = 0; i < numTabs; i++)
        {
            Serial.print('\t');
        }
        Serial.print(entry.name());
        if (entry.isDirectory())
        {
            Serial.println("/");
            printDirectory(entry, numTabs + 1);
        }
        else
        {
            // files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
        }
        entry.close();
    }
}

void SDList()
{
    root = SD.open("/");
    printDirectory(root, 0);
}