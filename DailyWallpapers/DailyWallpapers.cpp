#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

const wchar_t* srcUrl = L"https://www.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1&mkt=en-US";
const wchar_t* destination = L"bDW.json";
const wchar_t* tempDest = L"dailyWall.jpg";

int OldDate = 0;
int NewDate = 0;

float timeDelta = 0;
clock_t clk = clock(), temp;

int main()
{
    system("color 0E");
    std::cout << "Starting app...\n\nThis console will automatically close in 5 seconds!\n";
    Sleep(5000);
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    while (1)
    {
        if (S_OK == URLDownloadToFile(NULL, srcUrl, destination, 0, NULL))
        {
            std::cout << "Saved to " << destination << "\n\n";
        }
        else { std::cout << "Failed to acquire file.\n"; }

        std::ifstream f("bDW.json");
        json data = json::parse(f);

        std::string bingSrc = "https://www.bing.com";
        std::string cleanedUp;
        cleanedUp = to_string(data["images"][0]["url"]);
        cleanedUp.erase(remove(cleanedUp.begin(), cleanedUp.end(), '\"'));
        bingSrc.append(cleanedUp);

        std::wstring stemp = std::wstring(bingSrc.begin(), bingSrc.end());
        LPCWSTR sw = stemp.c_str();

        if (S_OK == URLDownloadToFile(NULL, sw, tempDest, 0, NULL))
        {
            std::cout << "Saved file to " << tempDest << "\n";
        }
        else { std::cout << "Unable to acquire file.\n"; }

        BOOL success = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (wchar_t*)"dailyWall.jpg", SPIF_UPDATEINIFILE);

        if (!(success))
            std::cout << "Failed to set the background!\n";
        else
            std::cout << "Background successfully changed!\n";


        std::this_thread::sleep_for(std::chrono::minutes(10));
    }
}