//add include statements
#include "func.h"
#include "iostream"

using std::string;
using std::cout;

//add function code here

double get_gc_content(const string& dna)
{
    //get length of dna string, get the occurances of g and c and divide by the length
    int dna_length = dna.length();

    double gc_counter = 0;
    for (int i = 0; i < dna_length; i++)
    {   
        if( dna[i] == 'G' || dna[i] == 'C')
        {
            gc_counter++;
        }
    }
    double result = gc_counter/dna_length;
    return result;
}

string reverse_string(string dna)
{
    int dna_length = dna.length();
    string dna_reversed;
    for(int i = dna_length - 1; i >= 0; i--)
    {
        string current_char(1,dna[i]);
        dna_reversed.append(current_char);
    }
    return dna_reversed;

}

string get_dna_complement(string dna)
{
    int dna_length = dna.length();
    string dna_complement = reverse_string(dna);

    for (int i = 0; i < dna_length; i++)
    {
        if ( dna_complement[i] == 'A')
        {
            dna_complement[i] = 'T';
        }
        else if ( dna_complement[i] == 'T')
        {
            dna_complement[i] = 'A';
        }
        else if ( dna_complement[i] == 'G')
        {
            dna_complement[i] = 'C';
        }
        else if ( dna_complement[i] == 'C')
        {
            dna_complement[i] = 'G';
        }
    }
    return dna_complement;
}