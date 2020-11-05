#include "dp.h"
#include "gen.h"
#include <assert.h>

void test_highest_tower1() {
    auto stream = std::stringstream();

    //2 bricks: 1x2x3 and 1x4x5
    stream << "2\n1 2 3\n1 4 5\n";

    Tower t = get_highest_tower(stream);

    assert(t.depth == 6);
    assert(t.bricks.size() == 2);
}

void test_highest_tower2() {
    auto stream1= std::stringstream();
    stream1 << "6\n1 1 1\n2 2 2\n3 3 3\n4 4 4\n5 5 5\n6 6 6\n";

    auto stream2 = std::stringstream();
    stream2 << "6\n3 3 3\n6 6 6\n1 1 1\n4 4 4\n2 2 2\n5 5 5\n";

    Tower t1 = get_highest_tower(stream1);
    Tower t2 = get_highest_tower(stream2);

    assert(t1.depth == t2.depth);
    assert(t1.bricks.size() == t2.bricks.size());
    assert(t1.depth == 21);
    assert(t1.bricks.size() == 6);
}

void test_tower_correctness() {
    auto stream = std::stringstream();
    generate(1000, 1, 1000, stream);

    Tower tower = get_highest_tower(stream);
    int size = tower.bricks.size();
    double depth = tower.bricks.front().depth;
    for (int i = 1; i < size; ++i) {
        assert(tower.bricks[i].width > tower.bricks[i - 1].width && 
                tower.bricks[i].height > tower.bricks[i - 1].height);
        depth += tower.bricks[i].depth;
    }
    assert(depth == tower.depth);
}

int main() {
    test_highest_tower1();
    test_highest_tower2();
    test_tower_correctness();
}