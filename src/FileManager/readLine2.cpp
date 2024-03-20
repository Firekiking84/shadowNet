// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 20/03/2024 16:59:40 ******************************************************
// keryan.houssin <keryan.houssin@aldrin.efrits.fr>
// - ShadowNet -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "fileManager.hh"

int ef::FileManager::readLine(char *tab,
                              unsigned int tabSize,
                              char delim)
{
    if (stream.is_open())
    {
        stream.getline(tab, tabSize, delim);
        //std::getline(*this, *tab);
        return 1;
    }
    return -1;
}

