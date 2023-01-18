class Oltas
{
    std::string name;

public:
    Oltas(const std::string &name) : name(name) {}
    std::string getName() { return name; }
    virtual std::string getType() = 0;
};

class Pfizer : public Oltas
{
    Pfizer(const std::string &name) : Oltas(name) {}
    Pfizer(Pfizer &other) = delete;
    Pfizer &operator=(Pfizer &other) = delete;

public:
    static Oltas *GetInstance()
    {
        static Pfizer instance("Pfizer");
        return &instance;
    }
    std::string getType()
    {
        return "mRNA";
    }
};

class Sinovac : public Oltas
{
    Sinovac(const std::string &name) : Oltas(name) {}
    Sinovac(Sinovac &other) = delete;
    Sinovac &operator=(Sinovac &other) = delete;

public:
    static Oltas *GetInstance()
    {
        static Sinovac instance("Sinovac");
        return &instance;
    }
    std::string getType()
    {
        return "adenovirus";
    }
};

class OltasiIgazolas
{
    std::vector<Oltas *> oltasok;

public:
    OltasiIgazolas(const std::vector<Oltas *> &oltasok) : oltasok(oltasok) {}
    int getCount(Oltas *whichOltas)
    {
        /*int count = 0;
        for (Oltas* op : oltasok) {
            if (op == whichOltas) {
                count++;
            }
        }
        return count;*/

        // a fenti mukodik, de meg egyszerubb:
        return std::count(oltasok.begin(), oltasok.end(), whichOltas);

        // itt egy un. predicate fuggvenyt adunk meg, ez is jo, de
        // itt feleslegesen bonyolult:
        /*return std::count_if(
            oltasok.begin(), oltasok.end(),
            [whichOltas](Oltas* current) {
                return current == whichOltas;
            }
        );*/
    }
};

typedef std::pair<Oltas *, int> Kovetelmeny;
typedef std::vector<Kovetelmeny> Kovetelmenyek;