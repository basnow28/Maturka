#include <iostream>
#include <fstream>

using namespace std;

int howManyPicselsInLineAreDark(int line, int howManyPicsInLine, char picture[20][20])
{
    int howManyPicsInDark = 0;

    for(int i=0; i<howManyPicsInLine; i++)
    {
        if(picture[i][line] == '1')
        {
            howManyPicsInDark += 1;
        }
    }
    return howManyPicsInDark;
}


int howManyPicsAreDarkInPicture(int howManyLines, char picture[20][20])
{
    int howManyPicsAreDarkInWholePicture = 0;

    for(int i=0; i<howManyLines; i++)
    {
        howManyPicsAreDarkInWholePicture += howManyPicselsInLineAreDark(i, howManyLines, picture);
    }

    return howManyPicsAreDarkInWholePicture;
}

bool isThePictureRewers(int howManyLines, char picture[20][20])
{
    int howManyPicsAreDark;
    int howManyPicsAreWhite;

    howManyPicsAreDark = howManyPicsAreDarkInPicture(howManyLines, picture);
    howManyPicsAreWhite = howManyLines*howManyLines - howManyPicsAreDark;

    if(howManyPicsAreDark > howManyPicsAreWhite)
    {
        return true;
    }
    return false;
}

bool isThePictureRecurency(int howManyLines, char picture[20][20])
{
    int differenceBetweenPics = howManyLines/2;
    for(int i=0; i<howManyLines/2; i++)
    {
        for(int j=0; j<howManyLines/2; j++)
        {
            if(picture[i][j] != picture[i+differenceBetweenPics][j]) return false;
            if(picture[i][j] != picture[i][j+differenceBetweenPics]) return false;
            if(picture[i][j] != picture[i+differenceBetweenPics][j+differenceBetweenPics]) return false;
        }
    }
    return true;
}

void displayPicture(int howManyLines, char picture[20][20])
{
    for(int i=0; i<howManyLines; i++)
    {
        for(int j=0; j<howManyLines; j++)
        {
            cout << picture[j][i];
        }
        cout << endl;
    }
}
int main()
{
    fstream file;
    file.open("dane_obrazki.txt");
    char picture[20][20];
    char verticalEvenBites[20];
    char horizontalEvenBites[20];
    int whichPictureIsNow = 1;
    int howManyLines = 20;
    int howManyRewerses = 0;
    int maximumQuantityOfDark = 0;
    int quantityOfDark = 0;
    int recurencyPictures = 0;
    int recPic = 0;

    if(file.good())
    {
        while(whichPictureIsNow <= 200)
        {
            for(int x=0; x<howManyLines; x++)
            {
                for(int y=0; y<howManyLines; y++)
                {
                    file >> picture[y][x];
                }
                file >> verticalEvenBites[x];
            }

            for(int x=0; x<howManyLines; x++)
            {
                file >> horizontalEvenBites[x];
            }

            if(isThePictureRewers(howManyLines, picture))
            {
                howManyRewerses += 1;
            }
            whichPictureIsNow += 1;

            quantityOfDark = howManyPicsAreDarkInPicture(howManyLines, picture);

            if(quantityOfDark > maximumQuantityOfDark)
            {
                maximumQuantityOfDark = quantityOfDark;
            }

            if(isThePictureRecurency(howManyLines, picture))
            {
                recurencyPictures += 1;
            }
        }
    }

    return 0;
}
