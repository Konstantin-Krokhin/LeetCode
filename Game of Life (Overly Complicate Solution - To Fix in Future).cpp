class Solution {
public:

    void handleSmallLife(vector<vector<int>>& board, int i, int j, int counter)
    {
        while (i < board.size())
        {
            j = 0;
            while (j < board[0].size())
            {
                if (board[i][j] == 1)
                    counter++;
                j++;
            }
                
            i++;
        }

        i = 0;
        int maj, prev = 0;
        if (board.size() > board[0].size()) maj = board.size();
        else maj = board[0].size();
        while (i < board.size())
        {
            j = 0;
            while (j < board[0].size())
            {
                if (board[0].size() == 1 && j != 0 && j != board.size() - 1)
                {
                    if ((prev == 1 || board[i][j - 1] == 1) && (board[i][j] == 1 && (board[i + 1][j] == 1) || board[i][j + 1] == 1))
                        board[i][j] = 1;
                    else
                    {
                        if (board[i][j] == 1)
                        {
                            prev = 1;
                            board[i][j] = 0;
                        }
                        else prev = 0;
                    }
                }
                else if (board[0].size() == 1 && j == 0)
                {
                    if (i > 0 && i < board.size() - 1 && (board[i - 1][j] == 1 || prev == 1) && board[i + 1][j] == 1 && board[i][j] == 1)
                        board[i][j] = 1;
                    else if (board[i][j] == 1)
                    {
                        prev = 1;
                        board[i][j] = 0;
                    }
                    else prev = 0;
                }
                else if (counter > (maj / 2) && counter > 2) board[i][j] = 1;
                else
                {
                    if (board[i][j] == 1)
                    {
                        prev = 1;
                        board[i][j] = 0;
                    }
                    else prev = 0;
                }
                j++;
            }
            i++;
        }
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        // Create a map of values cell : Amount of neighbours
        unordered_map<int, int> live_neighbours;
        int i = 0, j = 0, counter = 0, k, n = 0;

        if (board.size() * board[0].size() <= 4 || ((board.size() < 2 && board[0].size() < 5) || (board[0].size() < 2)) )
        {
            handleSmallLife(board, i, j, counter);    
            return;
        }

        // Run and count each neighbours
        while (i < board.size())
        {
            j = 0;
            while (j < board[0].size())
            {
                counter = 0;
                // Come up with formula for counting each neighbour based on the length of row (do it differently for 1st and last and edges)
                // Follow the rules of counting neighbours (if not edges)
                if (i > 0 && i < board.size() - 1 && j > 0 && j < board[0].size() - 1)
                {
                    if (board[i][j - 1] == 1)
                        counter++;
                    if (board[i][j + 1] == 1)
                        counter++;
                    if (board[i - 1][j] == 1)
                        counter++;
                    if (board[i + 1][j] == 1)
                        counter++;
                    if (board[i - 1][j + 1] == 1)
                        counter++;
                    if (board[i - 1][j - 1] == 1)
                        counter++;
                    if (board[i + 1][j + 1] == 1)
                        counter++;
                    if (board[i + 1][j - 1] == 1)
                        counter++;
                    
                    live_neighbours[n++] = counter;
                }
                else if (i == 0 && j == 0) // Counting corners
                {
                    if (board[i][j + 1] == 1)
                        counter++;
                    if (board[i + 1][j + 1] == 1)
                        counter++;
                    if (board[i + 1][j] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (i == 0 && j == board[0].size() - 1)
                {
                    if (board[i][j - 1] == 1)
                        counter++;
                    if (board[i + 1][j - 1] == 1)
                        counter++;
                    if (board[i + 1][j] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (i == board.size() - 1 && j == board[0].size() - 1)
                {
                    if (board[i][j - 1] == 1)
                        counter++;
                    if (board[i - 1][j - 1] == 1)
                        counter++;
                    if (board[i - 1][j] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (i == board.size() - 1 && j == 0)
                {
                    if (board[i][j + 1] == 1)
                        counter++;
                    if (board[i - 1][j + 1] == 1)
                        counter++;
                    if (board[i - 1][j] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (i == 0)
                {
                    if (board[i + 1][j] == 1)
                        counter++;
                    if (board[i + 1][j - 1] == 1)
                        counter++;
                    if (board[i + 1][j + 1] == 1)
                        counter++;
                    if (board[i][j + 1] == 1)
                        counter++;
                    if (board[i][j - 1] == 1)
                        counter++;
                    

                    live_neighbours[n++] = counter;
                }
                else if (i == board.size() - 1)
                {
                    if (board[i - 1][j] == 1)
                        counter++;
                    if (board[i - 1][j - 1] == 1)
                        counter++;
                    if (board[i - 1][j + 1] == 1)
                        counter++;
                    if (board[i][j - 1] == 1)
                        counter++;
                    if (board[i][j + 1] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (j == board[0].size() - 1)
                {
                    if (board[i - 1][j] == 1)
                        counter++;
                    if (board[i][j - 1] == 1)
                        counter++;
                    if (board[i + 1][j] == 1)
                        counter++;
                    if (board[i + 1][j - 1] == 1)
                        counter++;
                    if (board[i - 1][j - 1] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                else if (j == 0)
                {
                    if (board[i - 1][j] == 1)
                        counter++;
                    if (board[i][j + 1] == 1)
                        counter++;
                    if (board[i + 1][j] == 1)
                        counter++;
                    if (board[i - 1][j + 1] == 1)
                        counter++;
                    if (board[i + 1][j + 1] == 1)
                        counter++;
                    live_neighbours[n++] = counter;
                }
                j++;
            }
            i++;
        }

        i = 0;
        // Updated based on the count each cell
        while (i < live_neighbours.size())
        {
            j = board[0].size() - (board[0].size() - (i % board[0].size()));
            k = i / board[0].size();

            if (j == board[0].size())
                j -= 1;
            if (k == board.size())
                k -= 1;

            if (live_neighbours[i] < 2)
                board[k][j] = 0;
            else if (live_neighbours[i] == 2)
            {
                if (board[k][j] == 1)
                    board[k][j] = 1;    
            }
            else if (live_neighbours[i] == 3)
                board[k][j] = 1;
            else if (live_neighbours[i] > 3)
                board[k][j] = 0;
            i++;
        }
    }
};