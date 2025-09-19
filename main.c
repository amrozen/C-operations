/**********************
Name : Amit Rozenfeld
ID : 207811324
Assignment: miluim project
***********************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Episode {
    char* name;
    int season;
    int episode;
    struct Episode* next;
} Episode;
typedef struct Series {
    char* name;
    int numEpisodes;
    Episode* episodes;
} Series;
typedef struct SeriesList {
    Series* series;
    struct SeriesList* next;
} SeriesList;
typedef struct User {
    char* name;
    int numLists;
    SeriesList** seriesLists;
    struct User* next;
} User;
typedef struct UserDB {
    User* users;
    int numUsers;
} UserDB;

//void mainmenu();
int numLength();
int biggerNum();
int recPow();

void menu1();
void baseToDec();
void decToBase();
void plus();
void primeFactorization();
void printDiamond();

void menu2();
void reverseString();
void reverseStringRec();
void absDiffNums();
void adnRec();
void adnCounter();
void subsetSum();
void createArrayRec();
void sortArrayOnce();
void sortArray();
int subsetSumRec();
void printArray();

void menu3();
void initUserDB();
void addUser();
void addSeries();
void addEpisode();
void printUserDB();
void clearUserDB();
void clearEpisodes();
void clearSeries();
void clearUsers();
User* findUser();
Series* findSeries();


int main() {
    // main menu
    int mainChoice;
    do {
        printf("Choose an option:\n1. basic operations and flow\n2. recursion\n3. data structures\n4. exit\n");
        scanf("%d", &mainChoice);
        switch (mainChoice) {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            default:
                break;
        }
    } while (mainChoice != 4);
    return 0;
}

//menu 1 function
void menu1() {
    int choice1;
    do {
        printf("Choose an option:\n1. baseToDec\n2. decToBase\n3. plus\n4. prime factorization\n5. print diamond\n6. exit\n");
        scanf("%d", &choice1);
        switch (choice1) {
            case 1:
                baseToDec();
                break;
            case 2:
                decToBase();
                break;
            case 3:
                plus();
                break;
            case 4:
                primeFactorization();
                break;
            case 5:
                printDiamond();
                break;
            default:
                break;
        }
    } while (choice1 != 6);
}

// base 2 dec function
void baseToDec() {
    int base, num, result = 0, power = 0;
    printf("Enter a base and a number in said base:");
    scanf("%d %d", &base, &num);
    do {
        result += (num % 10) * recPow(base, power);
        power++;
        num /= 10;
    } while (num > 0);
    printf("%d\n", result);
}

// dec 2 base function
void decToBase() {
    int num, base, result = 0, power = 0;
    printf("Enter a counting base and a decimal number:");
    scanf("%d %d", &base, &num);
    do {
        result += (num % base) * recPow(10, power);
        num /= base;
        power++;
    } while (num > 0);
    printf("%d\n", result);
}

// binary plus function
void plus() {
    int binum1, binum2;
    printf("Enter 2 binary numbers:\n");
    scanf("%d %d", &binum1, &binum2);
    // declaring bigger num as big and smaller as small:
    int big = biggerNum(binum1, binum2);
    int small;
    if (binum1 == big) {
        small = binum2;
    }
    else {
        small = binum1;
    }
    // calculating the result of the addition:
    int result = 0, extra = 0, index = 0;
    while (binum1 > 0 || binum2 > 0) {
        int lsb1 = binum1 % 10;
        int lsb2 = binum2 % 10;
        result += ((lsb1 + lsb2 + extra) % 2) * recPow(10, index);
        extra = ((lsb1 + lsb2 + extra) / 2);
        index++;
        binum1 /= 10;
        binum2 /= 10;
    }if (extra != 0) {
        result += recPow(10, index);
    }
    // printing the result with the right padding:
    int reslen = numLength(result);
    int blen = numLength(big);
    int slen = numLength(small);
    if (reslen > blen) {
        printf("0");
    }printf("%d\n+\n", big);
    for (int i = slen; i < reslen; i++) {
        printf("0");
    }printf("%d\n", small);
    for (int i = 0; i < reslen; i++) {
        printf("-");
    }printf("\n%d\n", result);
}

// prime factorization function:
void primeFactorization() {
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    if (number <= 1) {
        printf("%d", number);
        return;
    }
    while (number % 2 == 0) {
        printf("2 ");
        number /= 2;
    }
    for (int i = 3; i <= number; i += 2) {
        while (number % i == 0) {
            printf("%d ", i);
            number /= i;
        }
    } printf("\n");
}

// print diamond function
void printDiamond() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int upto = number;
    // every line from 1 to max stars
    for (int i = 1; i <= (2 * number - 1); i += 2) {
        //printing set of spaces
        for (int j = 1; j < upto; j++) {
            printf(" ");
        }
        //printing set of stars
        for (int n = 0; n < i; n++) {
            printf("*");
        }
        printf("\n");
        upto--;
    }

    int downfrom = number;
    // every line from max stars to 1 (without max stars line)
    for (int i = (2 * number - 3); i > 0; i -= 2) {
        //printing set of spaces
        for (int j = (number - 1); j < downfrom; j++) {
            printf(" ");
        }
        //printing set of stars
        for (int n = 0; n < i; n++) {
            printf("*");
        }
        printf("\n");
        downfrom++;
    }
}

//  length of number function
int numLength(int num) {
    int len = 0;
    if (num == 0) {
        return 1;
    }while (num > 0) {
        len++;
        num /= 10;
    }return len;
}

// bigger number function
int biggerNum(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

// menu 2 function
void menu2() {
    int choice2;
    do {
        printf("Choose an option:\n1. reverse string\n2. abs diff nums\n3. subset sum\n4.longest increasing subarray\n5. exit\n");
        scanf("%d", &choice2);
        switch (choice2) {
            case 1:
                reverseString();
                break;
            case 2:
                absDiffNums();
                break;
            case 3:
                subsetSum();
                break;
                //case 4:
                //();
                //break;
            default:
                break;
        }
    } while (choice2 != 5);
}

// reverse string function
void reverseString() {
    int size, tmp;
    char string[100];
    printf("Enter a size: ");
    scanf("%d", &size);
    printf("Enter a string: ");
    tmp = scanf("%s", &string);
    reverseStringRec(string, size);
    printf("\n");
    return;
}

//recursive function - returns reversed string
void reverseStringRec(char string[], int size) {
    if (size == 0) {
        return;
    }printf("%c", string[size - 1]);
    return reverseStringRec(string, (size - 1));
}

//abs diff nums main general function
void absDiffNums() {
    int len, diff;
    printf("Enter N and K:\n");
    scanf("%d %d", &len, &diff);
    int current = 1;
    adnCounter(len, diff, current);
}

//abs diff nums counter function (1-9)
void adnCounter(int n, int k, int c) {
    if (c > 9) {
        return;
    }
    int sum = c * (recPow(10, (n - 1)));
    adnRec((n - 1), k, c, sum);
    adnCounter(n, k, (c + 1));
}

//abs dif nums actual function
void adnRec(int n, int k, int c, int s) {
    if (n <= 0) {
        printf("%d\n", s);
        return;
    }
    if (((c - k) >= 0) && ((c - k) != (c + k))) {
        int nsum = s + ((c - k) * recPow(10, (n - 1)));
        adnRec((n - 1), k, (c - k), nsum);
    }
    if ((c + k) <= 9) {
        int nsum = s + ((c + k) * recPow(10, (n - 1)));
        adnRec((n - 1), k, (c + k), nsum);
    }
}

//recursive function - calculates power
int recPow(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int result = base * recPow(base, (exponent - 1));
    return result;
}

//subsetSum main general function
void subsetSum() {
    int size, target, cur = 0, counter = 0;
    printf("Enter the size of the array(max 20): ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    createArrayRec(arr, size, cur);
    sortArray(arr, size, cur, counter);
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int subArr[size];
    int sum = 0;
    if ((subsetSumRec(arr, size, subArr, target, sum, cur)) == 0) {
        printf("No such subset");
        return;
    }
    printArray(subArr, size, cur);
    printf("/n");
}

// subsetSum actual recursive function
int subsetSumRec(int arr[], int size, int subArr[], int target, int sum, int cur) {
    if (sum > target || cur >= size) {
        return 0;
    }
    if (sum == target) {
        return 1;
    }
    subArr[cur] = arr[cur];
    if (subsetSumRec(arr, size, subArr, target, sum + arr[cur], cur + 1)) {
        return 1;
    }
    subArr[cur] = 0;
    return subsetSumRec(arr, size, subArr, target, sum, cur + 1);
}

// recursive function that creates an array using user input
void createArrayRec(int arr[], int size, int cur) {
    if (size == cur) {
        return;
    }
    scanf("%d", &arr[cur]);
    createArrayRec(arr, size, cur + 1);
}

// recursive function that runs through the array and sorts it once
void sortArrayOnce(int arr[], int size, int cur) {
    int tmp;
    if (cur == size - 1) {
        return;
    }
    if (arr[cur] > arr[cur + 1]) {
        tmp = arr[cur];
        arr[cur] = arr[cur + 1];
        arr[cur + 1] = tmp;
    }
    sortArrayOnce(arr, size, cur + 1);
}

// recursive function that calls sortArrayOnce and runs it as many times needed (bubble sort)
void sortArray(int arr[], int size, int cur, int counter) {
    if (counter == size) {
        return;
    }
    sortArrayOnce(arr, size, cur);
    sortArray(arr, size, 0, counter + 1);
}

// recursive function that prints arrays
void printArray(int array[], int size, int cur) {
    if (cur >= size) {
        return;
    }
    if (array[cur] != 0) {
        printf("%d", array[cur]);
    }
    printArray(array, size, cur + 1);
}

void menu3(){
int choice3;
UserDB userDB;
do {
printf("1. Initialize UserDB\n2. Add User\n3. Add Series\n4. Add Episode\n5. Print UserDB\n6. Clear UserDB\n7. exit\n");
scanf("%d", &choice3);
switch (choice3) {
case 1:
initUserDB(&userDB);
break;
case 2:
addUser(&userDB);
break;
case 3:
addSeries(&userDB);
break;
case 4:
addEpisode(&userDB);
break;
case 5:
printUserDB(&userDB);
break;
case 6:
clearUserDB(&userDB);
break;
default:
break;
}
} while (choice3 != 7);
}

void initUserDB(UserDB* userDB) {
    userDB->users = NULL;
    userDB->numUsers = 0;
}

void addUser(UserDB* userDB) {
    char* name = (char*)malloc(100 * sizeof(char));
    if (name == NULL) {
        printf("name memory allocation failed");
        return;
    }
    printf("Enter user name: ");
    scanf("%s", name);
    if ((findUser(userDB, name)) != NULL) {
        printf("User already exists\n");
        free(name);
        return;
    }

    // if this the first user added to DB
    if (userDB->users == NULL) {
        userDB->users = (User*)malloc(sizeof(User));
        if (userDB->users == NULL) {
            free(name);
            printf("user memory allocation failed");
            return;
        }
        userDB->users->name = name;
        userDB->users->numLists = 0;
        userDB->users->seriesLists = NULL;
        userDB->users->next = NULL;
        userDB->numUsers++;
        return;
    }
    // if this is not the first user added
    User* lastUser = userDB->users;
    while (lastUser->next != NULL) {
        lastUser = lastUser->next;
    }
    lastUser->next = (User*)malloc(sizeof(User));
    if (lastUser->next == NULL) {
        free(name);
        printf("user memory allocation failed");
        return;
    }
    lastUser->next->name = name;
    lastUser->next->numLists = 0;
    lastUser->next->seriesLists = NULL;
    lastUser->next->next = NULL;
    userDB->numUsers++;
}

void addSeries(UserDB* userDB) {
    char name[100];
    printf("Enter user name: ");
    scanf("%s", name);
    User* curUser = findUser(userDB, name);
    if (curUser == NULL) {
        printf("User not found\n");
        return;
    }
    char* seriesName = (char*)malloc(100 * sizeof(char));
    if (seriesName == NULL) {
        printf("name memory allocation failed");
        return;
    }
    printf("Enter series name: ");
    scanf("%s", seriesName);
    if (findSeries(curUser, seriesName) != NULL) {
        printf("Series already exists\n");
        free(seriesName);
        return;
    }
    // if this is the user's first series
    if (curUser->numLists == 0) {
        curUser->seriesLists = (SeriesList**)calloc(1, sizeof(SeriesList*));
        if (curUser->seriesLists == NULL) {
            free(seriesName);
            return;
        }
        curUser->seriesLists[0] = (SeriesList*)malloc(sizeof(SeriesList));
        if (curUser->seriesLists[0] == NULL) {
            free(seriesName);
            free(curUser->seriesLists);
            return;
        }
        curUser->seriesLists[0]->next = NULL;
        curUser->seriesLists[0]->series = (Series*)malloc(sizeof(Series));
        if (curUser->seriesLists[0]->series == NULL) {
            free(seriesName);
            free(curUser->seriesLists[0]);
            free(curUser->seriesLists);
            return;
        }
        Series* curSeries = curUser->seriesLists[0]->series;
        curSeries->episodes = NULL;
        curSeries->numEpisodes = 0;
        curSeries->name = (char*)malloc(100 * sizeof(char));
        if (curSeries->name == NULL) {
            free(seriesName);
            free(curUser->seriesLists[0]->series);
            free(curUser->seriesLists[0]);
            free(curUser->seriesLists);
            return;
        }
        curSeries->name = seriesName;
        curUser->numLists++;
        return;
    }
    // if this isn't the users first series - either add to existing list or create a new one
    char choice;
    printf("Create a new list or add to an existing one? (n/e): ");
    scanf(" %c", &choice);
    switch (choice) {
        // user requested to create a new list
        case 'n':
        {
            SeriesList* tempList = (SeriesList*)malloc(sizeof(SeriesList));
            if (tempList == NULL) {
                free(seriesName);
                return;
            }
            tempList->next == NULL;
            tempList->series = (Series*)malloc(sizeof(Series));
            if (tempList->series == NULL) {
                free(seriesName);
                free(tempList);
                return;
            }
            tempList->series->episodes = NULL;
            tempList->series->numEpisodes = 0;
            tempList->series->name = seriesName;
            SeriesList** temporary = (SeriesList**)realloc(curUser->seriesLists, (curUser->numLists + 1) * sizeof(SeriesList*));
            if (temporary == NULL) {
                free(seriesName);
                free(tempList->series);
                free(tempList);
                return;
            }
            curUser->seriesLists = temporary;
            curUser->seriesLists[curUser->numLists] = tempList;
            curUser->numLists++;
            return;
        }
            // user requested to add to an existing list
        case 'e':
        {
            int index = 0;
            printf("Enter list index (0-%d): ", (curUser->numLists - 1));
            scanf("%d", &index);
            if (index >= curUser->numLists || index < 0) {
                printf("Invalid index\n");
                return;
            }
            SeriesList* lastSeries = curUser->seriesLists[index];
            while (lastSeries->next != NULL) {
                lastSeries = lastSeries->next;
            }
            lastSeries->next = (SeriesList*)malloc(sizeof(SeriesList));
            if (lastSeries->next == NULL) {
                printf("seriesList memory allocation failed");
                free(seriesName);
                return;
            }
            lastSeries->next->next = NULL;
            lastSeries->next->series = (Series*)malloc(sizeof(Series));
            if (lastSeries->next->series == NULL) {
                printf("Series memory allocation failed");
                free(seriesName);
                free(lastSeries->next);
                return;
            }
            lastSeries->next->series->episodes = NULL;
            lastSeries->next->series->numEpisodes = 0;
            lastSeries->next->series->name = seriesName;
            return;
        }
        default:
            printf("Invalid choice\n");
            free(seriesName);
            return;
    }
}

void addEpisode(UserDB* userDB) {
    char name[100];
    printf("Enter user name: ");
    scanf("%s", name);
    User* curUser = findUser(userDB, name);
    if (curUser == NULL) {
        printf("User not found\n");
        return;
    }
    char seriesName[100];
    printf("Enter series name: ");
    scanf("%s", seriesName);
    Series* curSeries = findSeries(curUser, seriesName);
    if (curSeries == NULL) {
        printf("Series not found\n");
        return;
    }
    char episodeName[100];
    int seasonNum = 0, episodeNum = 0;
    printf("Enter episode name: ");
    scanf("%s", episodeName);
    printf("Enter season and episode number: ");
    scanf("%d %d", &seasonNum, &episodeNum);
    Episode* newEpisode = (Episode*)malloc(sizeof(Episode));
    if (newEpisode == NULL)
        return;
    newEpisode->name = (char*)malloc(100 * sizeof(char));
    if (newEpisode->name == NULL) {
        free(newEpisode);
        return;
    }
    strcpy(newEpisode->name, episodeName);
    newEpisode->season = seasonNum;
    newEpisode->episode = episodeNum;
    newEpisode->next = NULL;
    // if this is the first episode added
    if (curSeries->episodes == NULL) {
        curSeries->episodes = newEpisode;
        curSeries->numEpisodes++;
        return;
    }
    // if new episode's place is at the beginning of the linked list
    Episode* rightPlace = curSeries->episodes;
    if (rightPlace->season > seasonNum || (rightPlace->season == seasonNum && rightPlace->episode >= episodeNum)) {
        newEpisode->next = curSeries->episodes;
        curSeries->episodes = newEpisode;
        curSeries->numEpisodes++;
        return;
    }
    // if this is not the first episode being added and we need to look for new episode's right place
    while (rightPlace->next != NULL) {
        if (rightPlace->next->season >= seasonNum)
            break;
        rightPlace = rightPlace->next;
    }
    //if season number already exists we need to continue searching for the right episode place
    if (rightPlace->next != NULL) {
        while (rightPlace->next->season == seasonNum && rightPlace->next->episode < episodeNum) {
            rightPlace = rightPlace->next;
        }
    }
    // inserting new episode into the linked list
    Episode* tmp = rightPlace->next;
    rightPlace->next = newEpisode;
    newEpisode->next = tmp;
    curSeries->numEpisodes++;
}

void printUserDB(UserDB* userDB) {
    User* currentUser = userDB->users;
    while (currentUser != NULL) {
        printf("User: %s\n", currentUser->name);
        for (int i = 0; i < currentUser->numLists; i++) {
            printf("List %d:\n", i);
            SeriesList* curSL = currentUser->seriesLists[i];
            while (curSL != NULL) {
                printf("%6s Series: %s\n", "", curSL->series->name);
                Episode* curEp = curSL->series->episodes;
                while (curEp != NULL) {
                    printf("%14s Season: %d, Episode: %d, \"%s\"\n", "", curEp->season, curEp->episode, curEp->name);
                    curEp = curEp->next;
                }
                curSL = curSL->next;
            }
        }
        currentUser = currentUser->next;
    }
}

void clearUserDB(UserDB* userDB) {
    User* currentUser = userDB->users;
    while (currentUser != NULL) {
        for (int i = 0; i < currentUser->numLists; i++) {
            clearEpisodes(currentUser->seriesLists[i]->series->episodes);
            clearSeries(currentUser->seriesLists[i]);
        }
        currentUser = currentUser->next;
    }
    clearUsers(userDB->users);
    userDB->numUsers = 0;
    userDB->users = NULL;
}

// helper function that recieves a series name and a pointer to a user, returns a pointer to the requested series
Series* findSeries(User* user, char* name) {
    for (int i = 0; i < user->numLists; i++) {
        SeriesList* curr = user->seriesLists[i];
        while (curr != NULL) {
            if (curr->series != NULL && strcmp(curr->series->name, name) == 0) {
                return curr->series;
            }
            curr = curr->next;
        }
    }
    return NULL;
}

// helper function that recieves a name and a pointer to the DB, returns a pointer to the requested user
User* findUser(UserDB* userDB, char* name) {
    User* cur = userDB->users;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// recursive helper function that erases all episodes of series
void clearEpisodes(Episode* episode) {
    if (episode == NULL)
        return;
    clearEpisodes(episode->next);
    if (episode->name != NULL)
        free(episode->name);
    free(episode);
}

// recursive helper function that erases all series list 
void clearSeries(SeriesList* serieList) {
    if (serieList == NULL)
        return;
    clearSeries(serieList->next);
    if (serieList->series->name != NULL)
        free(serieList->series->name);
    if (serieList->series != NULL)
        free(serieList->series);
    free(serieList);
}

// recursive helper function that erases all users
void clearUsers(User* user) {
    if (user == NULL)
        return;
    clearUsers(user->next);
    if (user->name != NULL)
        free(user->name);
    if (user->seriesLists != NULL)
        free(user->seriesLists);
    free(user);
}

