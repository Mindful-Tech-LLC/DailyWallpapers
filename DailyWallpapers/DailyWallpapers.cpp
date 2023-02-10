#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <urlmon.h>
#include <nlohmann/json.hpp>

#pragma comment(lib, "Urlmon.lib")

using json = nlohmann::json;

const wchar_t* srcUrl = L"https://www.bing.com/HPImageArchive.aspx?format=js&idx=0&n=1&mkt=en-US";
std::string bingUrl = "https://www.bing.com";
const wchar_t* jsonFile = L"bDW.json";
const wchar_t* fileName = L"dWall.png";

int OldDate = 0;
int NewDate = 0;

float timeDelta = 0;
clock_t clk = clock(), temp;

int main()
{
    system("color 0E");
    std::cout << "Starting app...\n\nThis window will automatically close in 5 seconds!\n";
    Sleep(5000);
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    while (true)
    {
        if (S_OK == URLDownloadToFile(NULL, srcUrl, jsonFile, 0, NULL))
        {
            std::cout << "Saved to " << jsonFile << "\n\n";
        }
        else { std::cout << "Failed to acquire file.\n"; }

        std::ifstream f(jsonFile);
        json data = json::parse(f);

        std::string cleanedUp;
        cleanedUp = to_string(data["images"][0]["url"]);
        cleanedUp.erase(remove(cleanedUp.begin(), cleanedUp.end(), '\"'));
        bingUrl.append(cleanedUp);

        std::wstring stemp = std::wstring(bingUrl.begin(), bingUrl.end());
        LPCWSTR sw = stemp.c_str();

        if (S_OK == URLDownloadToFile(NULL, sw, fileName, 0, NULL))
            std::cout << "Saved file to " << fileName << "\n";
        else
            std::cout << "Unable to acquire file.\n";

        BOOL success = SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, &fileName, SPIF_UPDATEINIFILE);
        
        if (!success)
            std::cout << GetLastError();
        else
            std::cout << "Successfully changed background!\n";

        std::this_thread::sleep_for(std::chrono::minutes(10));
    }
}