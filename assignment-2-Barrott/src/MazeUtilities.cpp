#include "MazeUtilities.h"

//overloaded output operator to output a vector
std::ostream &operator<<(std::ostream &output, std::vector<std::string> &v) {
    for (auto &n: v) {
        output << n << " " << std::endl;

    }
    return output;
}

//checks to see if coordinates are a valid move
bool valid_move(int x_pos, int y_pos, int gridsize, std::vector<std::string> map) {
    if ((x_pos >= 0 && x_pos < gridsize && y_pos >= 0 && y_pos < gridsize) && (map[y_pos][x_pos] == ' ')) {
        return true;
    } else {
        return false;
    }
}

//clears the maze of any asterisks markers
void clear_maze(std::vector<std::string> &map) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.size(); j++) {
            if (map[i][j] == '*') {
                map[i][j] = ' ';
            }
        }
    }
}

//marks the direct path on the map using '#'
void direct_path(std::vector<std::string> &map, Stack &stack) {
    while (stack.m_first != nullptr) {
        Coordinate coordinate = stack.peek();
        stack.pop();
        map[coordinate.m_y_pos][coordinate.m_x_pos] = '#';
    }
}

//opens file and saves it to a vector
std::vector<std::string> open_file_to_vector(std::string input_file) {
    std::string line;
    std::vector<std::string> v;
    std::ifstream file;

    file.open(input_file);


    if (file.is_open()) {

        std::cout << "File Open" << std::endl;
        while (!file.eof()) {

            getline(file, line);
            v.push_back(line);

        }
        file.close();
    }
    return v;
}

//saves a vector to a specified file path
void save_vector_to_file(std::vector<std::string> &map, const std::string& output_file) {
    std::ofstream file;
    file.open(output_file);

    if (file.is_open()) {
        for (int i = 0; i < map.size(); i++) {
            file << map[i] << std::endl;
        }
    }
    file.close();
}

//Main function which moves through the maze to find a way out
void run_maze(std::string input_path, std::string output_path) {

    std::vector<std::string> v = open_file_to_vector(input_path);
    Stack stack;
    Coordinate coord{};
    coord.m_y_pos = 1;
    coord.m_x_pos = 0;
    const int GRIDSIZE = 50;

    // Mark first postion of maze and push to stack
    v[coord.m_y_pos][coord.m_x_pos] = '*';
    stack.push(coord);

    // While loop to go until the x and y position hit 50 and 50, the end of the maze
    while (coord.m_x_pos < GRIDSIZE && coord.m_y_pos < GRIDSIZE) {

        if (valid_move(coord.m_x_pos, coord.m_y_pos + 1, v.size(), v)) {//look south
            //mark next spot with "*" to know where you have been and move forward and push coordinates to stack
            v[coord.m_y_pos + 1][coord.m_x_pos] = '*';
            coord.m_y_pos++;
            stack.push(coord);

        } else if (valid_move(coord.m_x_pos + 1, coord.m_y_pos, v.size(), v)) {//look east
            //mark next spot with "*" to know where you have been and move forward and push coordinates to stack
            v[coord.m_y_pos][coord.m_x_pos + 1] = '*';
            coord.m_x_pos++;
            stack.push(coord);

        } else if (valid_move(coord.m_x_pos, coord.m_y_pos - 1, v.size(), v)) {//look north
            //mark next spot with "*" to know where you have been and move forward and push coordinates to stack
            v[coord.m_y_pos - 1][coord.m_x_pos] = '*';
            coord.m_y_pos--;
            stack.push(coord);

        } else if (valid_move(coord.m_x_pos - 1, coord.m_y_pos, v.size(), v)) {//look west
            //mark next spot with "*" to know where you have been and move forward and push coordinates to stack
            v[coord.m_y_pos][coord.m_x_pos - 1] = '*';
            coord.m_x_pos--;
            stack.push(coord);

        } else {
            //If hitting this else its a dead end, pop coordinates off stack and move back
            stack.pop();
            coord = stack.peek();
        }

    }

    clear_maze(v);
    direct_path(v, stack);
    save_vector_to_file(v, output_path);
    std::cout<<"Maze written to file!"<<std::endl;

}