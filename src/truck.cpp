#include <vector>
#include <cPathFinder.h>

std::vector<std::vector<int>> cities =
    {{56, 15}, {62, 34}, {46, 49}, {89, 59}, {3, 44}, {13, 25}, {13, 90}, {33, 87}, {87, 58}, {99, 24}, {19, 4}, {11, 28}, {4, 0}, {70, 32}, {80, 31}};

std::vector<std::vector<int>> cluster1 =
    {{3, 44} , {13, 90} , {33, 87}};

std::vector<std::vector<int>> cluster2 =
    {{56, 15}, {62, 34}, {46, 49}, {89, 59}, {13, 25}, {87, 58}, {99, 24}, {19, 4}, {11, 28}, {4, 0}, {70, 32}, {80, 31}};


class cCity
{
public:
    cCity(int x, int y)
        : myX(x), myY(y)
    {
    }
    int pythag(const cCity &o)
    {
        int dx = myX - o.myX;
        int dy = myY - o.myY;
        return (sqrt(dx * dx + dy * dy));
    }

    int myX;
    int myY;
};
std::vector<cCity> vCity;

main()
{

    cPathFinder finder;

    for (auto &c : cluster2 )
    {
        vCity.push_back(cCity(c[0], c[1]));
    }

    std::ofstream cf("city.dat");
    for (int k1 = 0; k1 < vCity.size(); k1++)
    {
        auto sn1 = finder.findoradd(
            "c" + std::to_string(vCity[k1].myX) + "x" +
            std::to_string(vCity[k1].myY));

        cf << vCity[k1].myX << "," << vCity[k1].myY << "," 
            << "c" + std::to_string(vCity[k1].myX) + "x" +
            std::to_string(vCity[k1].myY) << "\n";

        for (int k2 = k1 + 1; k2 < vCity.size(); k2++)
        {
            auto sn2 = finder.findoradd(
                "c" + std::to_string(vCity[k2].myX) + "x" +
                std::to_string(vCity[k2].myY));

            finder.addLink(sn1, sn2, vCity[k1].pythag(vCity[k2]));

        }
    }

    std::cout << "\nLinks:\n" << finder.linksText() << "\n";

    finder.span();

    std::cout << "\nspan:\n" << finder.spanText() << "\n";

    std::ofstream fall("gall.dot");
    fall << finder.spanViz();
    std::ofstream f("g.dot");
    f << finder.spanViz(false);
}
