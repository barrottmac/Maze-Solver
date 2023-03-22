#include "MazeUtilities.h"

using namespace std;

int main(int argc, char *argv[]) {
    string input_path = argv[1];
    string output_path = argv[2];

    run_maze(input_path, output_path);

    return 0;
}