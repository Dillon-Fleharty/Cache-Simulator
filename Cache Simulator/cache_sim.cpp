#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* ********************************************************************
 *                          CLASS ENTRY
 *********************************************************************/
class Entry {
public:
    bool valid;
    size_t tag;

    Entry() : valid(false), tag(0) {}
};


/* ********************************************************************
 *                          CLASS CACHE
 *********************************************************************/
class CacheMoney /* ♬ Cache rules everything around me ♬ */ {
public:

    CacheMoney(size_t num_entries, size_t associativity) :
            num_entries(num_entries),
            associativity(associativity),
            num_sets(num_entries / associativity),
            sets(num_sets, vector<Entry>(associativity)) {}

    bool hit_or_miss(size_t address)
    {
        // Get set index and tag from the address
        size_t set_index = (address / associativity) % num_sets;
        size_t tag = address / num_entries;

        // Find the set and search for the tag in the set
        for (Entry& entry : sets[set_index])
        {
            if (entry.valid && entry.tag == tag) // If the tag is found it's a hit
            {
                return true;
            }
        } // end for (Entry& entry : sets[set_index])

        Entry* replace_entry = 0;

        // If the tag is not found, it's a miss.
        // Find an invalid or LRU entry to replace
        for (Entry& entry : sets[set_index])
        {
            if (!entry.valid)
            {
                replace_entry = &entry;
                break;
            }
        } // end for(Entry& entry : sets[])

        // If no entry is found, replace entry using LRU
        if (!replace_entry)
        {
            replace_entry = &sets[set_index][0];
        }

        // Update the cache entry with the new tag and set it to valid
        replace_entry->tag = tag;
        replace_entry->valid = true;

        return false;

    } // end bool hit_or_miss(size_t address)


private:
    size_t num_entries;
    size_t associativity;
    size_t num_sets;
    vector<vector<Entry> > sets;
};


/* ********************************************************************
 *                          Main Function
 *********************************************************************/
int main(int argc, char *argv[])
{
    size_t address;

    if (argc != 4)
    {
        cout<< "Usage: " << argv[0] <<
        " num_entries associativity reference_file" << endl;
        return 1;
    }

    size_t num_entries = stoi(argv[1]);
    size_t associativity = stoi(argv[2]);
    string reference_file = argv[3];

    ifstream infile(reference_file);

    if (!infile.is_open())
    {
        cout << "Error opening memory reference file '" << reference_file << "'." << endl;
        return 1;
    }

    CacheMoney cache(num_entries, associativity);

    ofstream outfile("cache_sim_output");

    while (infile >> address)
    {
        bool hit = cache.hit_or_miss(address);
        outfile << address << " : " << (hit ? "HIT" : "MISS") << endl;
    }

    infile.close();
    outfile.close();

    return 1;
} // end main()
