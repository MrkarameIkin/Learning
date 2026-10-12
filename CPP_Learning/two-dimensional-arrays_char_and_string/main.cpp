#include <iostream>

bool drawCheck(int board[3][3])
{
    if(board[0][0] != 0 and board[0][1] != 0 and board[0][2] != 0 and
       board[1][0] != 0 and board[1][1] != 0 and board[1][2] != 0 and
       board[2][0] != 0 and board[2][1] != 0 and board[2][2] != 0)
       {
        return 1;
       }
    return 0;
}

bool crossOfVictory(int board[3][3], int user)
{
    if(user == 1) // 1 - крестик, иначе 2 - нолик
    {
        if(board[0][0] == 1 and board[0][1] == 1 and board[0][2] == 1) return 1;
        if(board[1][0] == 1 and board[1][1] == 1 and board[1][2] == 1) return 1;
        if(board[2][0] == 1 and board[2][1] == 1 and board[2][2] == 1) return 1;
        if(board[0][0] == 1 and board[1][0] == 1 and board[2][0] == 1) return 1;
        if(board[0][1] == 1 and board[1][1] == 1 and board[2][1] == 1) return 1;
        if(board[0][2] == 1 and board[1][2] == 1 and board[2][2] == 1) return 1;
        if(board[0][0] == 1 and board[1][1] == 1 and board[2][2] == 1) return 1;
        if(board[2][0] == 1 and board[1][1] == 1 and board[0][2] == 1) return 1;
        return 0;
    }
    else
    {
        if(board[0][0] == 2 and board[0][1] == 2 and board[0][2] == 2) return 1;
        if(board[1][0] == 2 and board[1][1] == 2 and board[1][2] == 2) return 1;
        if(board[2][0] == 2 and board[2][1] == 2 and board[2][2] == 2) return 1;
        if(board[0][0] == 2 and board[1][0] == 2 and board[2][0] == 2) return 1;
        if(board[0][1] == 2 and board[1][1] == 2 and board[2][1] == 2) return 1;
        if(board[0][2] == 2 and board[1][2] == 2 and board[2][2] == 2) return 1;
        if(board[0][0] == 2 and board[1][1] == 2 and board[2][2] == 2) return 1;
        if(board[2][0] == 2 and board[1][1] == 2 and board[0][2] == 2) return 1;
        return 0;
    }
}

bool check(int board[3][3], int scores[2])
{
    if(drawCheck(board)) // если на доске нету нулей, то это ничья (игра сбрасывается и счет не меняется)
    {
        std::cout << "Ничья!\n";
        return 0;
    }
    else if(crossOfVictory(board, 1)) // перебор всех возможных комбинаций для победы крестиков
    {
        scores[0]++;
        return 0;
    }
    else if(crossOfVictory(board, 2)) // перебор всех возможных комбинаций для победы ноликов
    {
        scores[1]++;
        return 0;
    }
    else return 1; // если никто не выиграл и нету ничьей, то игра продолжается и выводится доска
}

void printBoard(int board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0) std::cout << " ";
            if(board[i][j] == 1) std::cout << "X";
            if(board[i][j] == 2) std::cout << "O";
            if(j == 2)std::cout << std::endl;
            else std::cout << " | ";
        }

        if(i!=2) std::cout << "-- -- --\n";
    }
}

int main()
{
    std::string userNames[2];
    int scores[2] = {0,0};
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}}; // 0 - пустое поле, 1 - Крестик, 2 - Нолик

    std::cout << "=== КРЕСТИКИ-НОЛИКИ ===\n";
    std::cout << "\nВведите имя игрока 1 (X): ";
    std::cin >> userNames[0];

    std::cout << "Введите имя игрока 2 (O): ";
    std::cin >> userNames[1];

    std::cout << "\nИгра началась!" << std::endl;

    bool flag = true; // true - крестики, false - нолики
    
    do
    {
        int lin, col;

        if(flag){
            std::cout << "\nХод игрока " << userNames[0] << " (X)";
            
            do
            {
                std::cout << "\nВведите строку (1-3): ";
                std::cin >> lin;
                std::cout << "Введите столбец (1-3): ";
                std::cin >> col;
                
                if(board[lin-1][col-1] == 0)
                {
                    board[lin-1][col-1] = 1;
                    break;
                }
                else std::cout << "Клетка занята!\n";
            }
            while(true);
        }
        else
        {
            std::cout << "\nХод игрока " << userNames[1] << " (O)";

            do
            {
                std::cout << "\nВведите строку (1-3): ";
                std::cin >> lin;
                std::cout << "Введите столбец (1-3): ";
                std::cin >> col;
                
                if(board[lin-1][col-1] == 0)
                {
                    board[lin-1][col-1] = 2;
                    break;
                }
                else std::cout << "Клетка занята!\n";
            }
            while(true);
        }

        if(check(board, scores))
        {
            printBoard(board);
            flag = !flag;
        }
        else // игра закончилась (когда кто-то выиграл или ничья)
        {
            char replay;
            std::cout << "\nСчет:\n";
            std::cout << userNames[0] << " (X): " << scores[0] << std::endl;
            std::cout << userNames[1] << " (O): " << scores[1] << std::endl;
            std::cout << "\nСыграть ещё раз? (y/n): ";

            do
            {
                std::cin >> replay;

                if(replay == 'y' or replay == 'n')
                {
                    board[0][0] = 0; board[0][1] = 0; board[0][2] = 0;
                    board[1][0] = 0; board[1][1] = 0; board[1][2] = 0;
                    board[2][0] = 0; board[2][1] = 0; board[2][2] = 0;
                    break;
                }
                else std::cout << "Неверный ввод! Попробуйте снова";
            }
            while(true);

            if(replay == 'n') break;
            flag = true;
        }
    }
    while(true);
}
