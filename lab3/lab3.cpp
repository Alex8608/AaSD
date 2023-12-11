#include "lab3.h"

int main() {
    const vector<size_t> vector_lengths = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };

   /* for (size_t length : vector_lengths) {

        stats selection_random_stats_sum{ 0, 0 };

        stats shaker_random_stats_sum{ 0, 0 };;

        stats comb_random_stats_sum{ 0, 0 };

        for (int i = 0; i < 100; ++i) {
            vector<int> random_vector = RandomVec<int>(length);

            vector<int> selection_random_vector = random_vector;
            stats selection_random_stats = SelectionSort(selection_random_vector);
            selection_random_stats_sum.comparison_count += selection_random_stats.comparison_count;
            selection_random_stats_sum.copy_count += selection_random_stats.copy_count;

            vector<int> shaker_random_vector = random_vector;
            stats shaker_random_stats = ShakerSort(shaker_random_vector);
            shaker_random_stats_sum.comparison_count += shaker_random_stats.comparison_count;
            shaker_random_stats_sum.copy_count += shaker_random_stats.copy_count;

            vector<int> comb_random_vector = random_vector;
            stats comb_random_stats = CombSort(comb_random_vector);
            comb_random_stats_sum.comparison_count += comb_random_stats.comparison_count;
            comb_random_stats_sum.copy_count += comb_random_stats.copy_count;

        }
        vector<int> sorted_vector = SortedVec<int>(length);

        vector<int> selection_sorted_vector = sorted_vector;
        stats selection_sorted_stats = SelectionSort(selection_sorted_vector);

        vector<int> shaker_sorted_vector = sorted_vector;
        stats shaker_sorted_stats = ShakerSort(shaker_sorted_vector);

        vector<int> comb_sorted_vector = sorted_vector;
        stats comb_sorted_stats = CombSort(comb_sorted_vector);

        vector<int> reverse_sorted_vector = ReverseSortedVec<int>(length);

        vector<int> selection_reverse_sorted_vector = reverse_sorted_vector;
        stats selection_reverse_sorted_stats = SelectionSort(selection_reverse_sorted_vector);

        vector<int> shaker_reverse_sorted_vector = reverse_sorted_vector;
        stats shaker_reverse_sorted_stats = ShakerSort(shaker_reverse_sorted_vector);

        vector<int> comb_reverse_sorted_vector = reverse_sorted_vector;
        stats comb_reverse_sorted_stats = CombSort(comb_reverse_sorted_vector);

        stats selection_random_mean_stats{
            selection_random_stats_sum.comparison_count / 100,
            selection_random_stats_sum.copy_count / 100
        };

        stats shaker_random_mean_stats{
            shaker_random_stats_sum.comparison_count / 100,
            shaker_random_stats_sum.copy_count / 100
        };

        stats comb_random_mean_stats{
            comb_random_stats_sum.comparison_count / 100,
            comb_random_stats_sum.copy_count / 100
        };

        ofstream selection_random_stats_file;
        selection_random_stats_file.open("C://1/AaSD/lab3/selection_random_stats_file.txt", ios::app | ios::out);
        selection_random_stats_file << selection_random_mean_stats;
        selection_random_stats_file.close();

        ofstream shaker_random_stats_file;
        shaker_random_stats_file.open("C://1/AaSD/lab3/shaker_random_stats_file.txt", ios::app | ios::out);
        shaker_random_stats_file << shaker_random_mean_stats;
        shaker_random_stats_file.close();

        ofstream comb_random_stats_file;
        comb_random_stats_file.open("C://1/AaSD/lab3/comb_random_stats_file.txt", ios::app | ios::out);
        comb_random_stats_file << comb_random_mean_stats;
        comb_random_stats_file.close();

        ofstream selection_sorted_stats_file;
        selection_sorted_stats_file.open("C://1/AaSD/lab3/selection_sorted_stats_file.txt", ios::app | ios::out);
        selection_sorted_stats_file << selection_sorted_stats;
        selection_sorted_stats_file.close();

        ofstream shaker_sorted_stats_file;
        shaker_sorted_stats_file.open("C://1/AaSD/lab3/shaker_sorted_stats_file.txt", ios::app | ios::out);
        shaker_sorted_stats_file << shaker_sorted_stats;
        shaker_sorted_stats_file.close();

        ofstream comb_sorted_stats_file;
        comb_sorted_stats_file.open("C://1/AaSD/lab3/comb_sorted_stats_file.txt", ios::app | ios::out);
        comb_sorted_stats_file << comb_sorted_stats;
        comb_sorted_stats_file.close();

        ofstream selection_reverse_sorted_stats_file;
        selection_reverse_sorted_stats_file.open("C://1/AaSD/lab3/selection_reverse_sorted_stats_file.txt", ios::app | ios::out);
        selection_reverse_sorted_stats_file << selection_reverse_sorted_stats;
        selection_reverse_sorted_stats_file.close();

        ofstream shaker_reverse_sorted_stats_file;
        shaker_reverse_sorted_stats_file.open("C://1/AaSD/lab3/shaker_reverse_sorted_stats_file.txt", ios::app | ios::out);
        shaker_reverse_sorted_stats_file << shaker_reverse_sorted_stats;
        shaker_reverse_sorted_stats_file.close();

        ofstream comb_reverse_sorted_stats_file;
        comb_reverse_sorted_stats_file.open("C://1/AaSD/lab3/comb_reverse_sorted_stats_file.txt", ios::app | ios::out);
        comb_reverse_sorted_stats_file << comb_reverse_sorted_stats;
        comb_reverse_sorted_stats_file.close();
    }*/

    vector<string> selection_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    vector<string> shaker_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    vector<string> comb_string_vec = { "n", "e", "s", "m", "d", "f", "c" , "v", "a", "r" , "j", "a", "x", "t", "y" , "u", "b", "e" , "q", "k", "l", "g", "b", "r" };
    stats selection_string_stats = SelectionSort(selection_string_vec);
    stats shaker_string_stats = ShakerSort(shaker_string_vec);
    stats comb_string_stats = CombSort(comb_string_vec);
    cout << selection_string_vec << selection_string_stats << endl;
    cout << shaker_string_vec << shaker_string_stats << endl;
    cout << comb_string_vec << comb_string_stats << endl;

    vector<MyClass> v1;
    vector<MyClass> v2;
    vector<MyClass> v3;

    
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v1.push_back(rand() % 100);
    }
    cout << v1 << "--------" << endl;
    stats selection_my_stats = SelectionSort(v1);
    cout << v1 << endl << "~~~~~~~~~~~~~~" << endl;

    
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v2.push_back(rand() % 100);
    }
    cout << v2 << "--------" << endl;
    stats shaker_my_stats = ShakerSort(v2);
    cout << v2 << endl << "~~~~~~~~~~~~~~" << endl;

    
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < 50; ++i) {
        v3.push_back(rand() % 100);
    }
    cout << v3 << "--------" << endl;
    stats comb_my_stats = CombSort(v3);
    cout << v3 << endl << "~~~~~~~~~~~~~~" << endl;


}