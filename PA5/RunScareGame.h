
class RunScareGame
{
private:
    std::string m_input;
    std::string m_output;
    std::string m_type;
public:
    RunScareGame();
    RunScareGame(std::string inputFile, std::string outputFile, std::string gameType);
    virtual ~RunScareGame();
    void runTournament();
};