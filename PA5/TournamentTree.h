#include <string>

class TournamentTree
{
private:
    int screamPower;
    std::string name;
public:
    TournamentTree(std::string name, int screamPower);
    virtual ~TournamentTree();
};
