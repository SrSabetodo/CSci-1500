/*
Bryant Yaurincela
Logan Kreun
Michael Bethke
CSCI 1730-01
Group 7
*/


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>


#ifdef _WIN32
#include <direct.h>
#define getcws _getcwd
#define PATH_SEPERATOR '\\'
#elif defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#include <unistd.h>
#define PATH_SEPERATOR '/'
#endif


class DynamicArray
{

public:
	DynamicArray ();
	~DynamicArray ();
	
	void push_back (const std::string value);
	const std::size_t get_data_size () const {return size;}
	const std::size_t get_data_length () const {return next_open_position;}
	
	void sort ();
	void swap (const unsigned int first_pos, const unsigned int second_pos);
	void remove (const std::size_t index);
	
	const unsigned int chars_count ();
	std::string words_of_length (const std::size_t target, const char delimiter);
	const unsigned int find_word (const std::string target);
	
	std::string &operator[] (const std::size_t index);
	
private:
	const static std::size_t DYNAMIC_ARRAY_BLOCK_SIZE = 32;
	
	std::string *data;
	std::size_t size;
	unsigned int next_open_position;
	
	void expand ();
	
	void bucket_sort ();
	void insertion_sort ();
};


DynamicArray::DynamicArray ()
{
	
	size = DYNAMIC_ARRAY_BLOCK_SIZE;
	data = new std::string [size];
	next_open_position = 0;
}


DynamicArray::~DynamicArray ()
{

	delete [] data;
}


std::string &DynamicArray::operator[] (const std::size_t index)
{
	
	if (index < size)
		return data[index];
	else {
		throw;
	}
}


void DynamicArray::push_back (const std::string value)
{
	
	if (next_open_position >= (size - 1))
	{
		
		expand ();
	}
	
	data[next_open_position] = value;
	next_open_position += 1;
}


void DynamicArray::expand ()
{
	
	std::string *new_data;
	new_data = new std::string [size + DYNAMIC_ARRAY_BLOCK_SIZE];
	
	for (int i = 0; i < size; i += 1)
	{
		
		new_data[i] = data[i];
	}
	
	size += DYNAMIC_ARRAY_BLOCK_SIZE;
	delete [] data;
	
	data = new_data;
}


void DynamicArray::sort()
{
	
	bucket_sort ();
}


void DynamicArray::bucket_sort ()
{
	
	DynamicArray buckets[11];
	
	for (int i = 0; i < get_data_length (); i += 1)
	{
		
		if (data[i].length () - 1 <= 10)
			buckets[data[i].length () - 1].push_back (data[i]);
		else
			buckets[10].push_back (data[i]);
		
		remove (i);
	}
	
	if (buckets[10].get_data_length () > 0)
		buckets[10].insertion_sort ();
	
	unsigned int insertion_offset = 0;
	for (int b = 0; b < 11; b += 1)
	{
		
		for (int e = 0; e < buckets[b].get_data_length (); e += 1)
		{
			
			data[insertion_offset + e] = buckets[b][e];
			//push_back (buckets[b][e]);	//USE IF ARRAY HAS BEEN SHRUNK
		}
		
		insertion_offset += buckets[b].get_data_length ();
	}
	
	//DEBUG BUCKETS
	/*for (int b = 0; b < 11; b += 1)
	{
		
		for (int w = 0; w < buckets[b].get_data_length (); w += 1)
		{
			
			std::cout << "bucket " << (b + 1) << " contains " << buckets[b].data[w] << std::endl;
		}
		
		std::cout << std::endl;
	}*/
}


void DynamicArray::insertion_sort ()
{

	for (int i = 1; i < get_data_length (); i += 1)
	{
		
		for (int j = (i - 1); j >= 0; j -= 1)
		{
			
			if (data[j].length () < data[j + 1].length ())
				break;
			
			swap (j, j + 1);
		}
	}
}


void DynamicArray::swap (const unsigned int first_pos, const unsigned int second_pos)
{
	
	std::string temp_container = data[first_pos];
	data[first_pos] = data[second_pos];
	data[second_pos] = temp_container;
}


void DynamicArray::remove (const std::size_t index)
{
	
	if (index <= size)
		data[index].clear ();
}


const unsigned int DynamicArray::chars_count ()
{
	
	unsigned int chars = 0;
	
	for (int w = 0; w < get_data_length (); w += 1)
	{
		
		for (int c = 0; c < data[w].length (); c += 1)
		{
			
			chars += 1;
		}
	}
	
	return chars;
}


std::string DynamicArray::words_of_length (const std::size_t target, const char delimiter)
{
	
	std::string target_words;

	int index = 0;
	short int step = 1;
	
	if (target != 1)
	{
		
		index = get_data_length () - 1;
		step = -1;
	}
	
	do
	{
		
		if (data[index].length () == target)
		{

			target_words.append (data[index]);
			target_words += delimiter;
		}
		
		index += step;
	} while (data[index].length () == target);
	
	return target_words;
}


const unsigned int DynamicArray::find_word (const std::string target)
{
	
	unsigned int count = 0;
	
	for (int f = 0; f < get_data_length (); f += 1)
	{
		
		if (data[f].length () == target.length ())
		{
			
			if (data[f] == target)
				count += 1;
		}
	}
	
	return count;
}


void remove_punctuation (std::string &temp_word, unsigned int &punctuation_chars)
{
	
	unsigned int left_pos;
	unsigned int right_pos;
	
	for (int i = 0; i < temp_word.length (); i += 1)
	{
		
		for (left_pos = 0; left_pos < temp_word.length (); left_pos += 1)
		{
			
			if (isalpha (temp_word[left_pos]))
				break;
		}
		
		for (right_pos = temp_word.length () - 1; right_pos > 0; right_pos -= 1)
		{
			
			//if (left_pos == right_pos) throw;
			
			if (isalpha (temp_word[right_pos]))
				break;
		}
		
		right_pos += 1;
		punctuation_chars += (left_pos + (temp_word.length () - right_pos));
		temp_word = temp_word.substr (left_pos, right_pos);
	}
}


int populate_array (std::ifstream &file, DynamicArray &array, unsigned int &punctuation_chars)
{
	
	std::string temp_word;
	bool review_for_punctuation = false;
	
	char c;
	while (file.get (c))
	{
		
		if (isgraph (c))
		{
			
			if (ispunct (c))
				review_for_punctuation = true;
			
			temp_word.push_back (c);
		} else {
			
			if (temp_word.length () > 0)
			{
				
				if (review_for_punctuation)
				{
					
					remove_punctuation (temp_word, punctuation_chars);
					review_for_punctuation = false;
				}
			
				//std::cout << "adding \'" << temp_word << '\'' << std::endl;
				array.push_back (temp_word);
				temp_word.clear ();
			}
		}
	}
	
	if (temp_word.length () > 0)
	{
		
		if (review_for_punctuation)
			remove_punctuation (temp_word, punctuation_chars);
	
		//std::cout << "adding \'" << temp_word << '\'' << std::endl;
		array.push_back (temp_word);
	}
	
	if (!file.fail ())
		return 0;
	else
		return 1;
}


bool is_filename (const std::string file_path)
{
	
	for (std::string::const_iterator i = file_path.begin (); i < file_path.end (); i += 1)
	{
		
		if (*i == '/' || *i == '\\')
			return false;
	}
	
	return true;
}


void clean_path (std::string &path)
{
	
	std::size_t first_char = path.find_first_not_of(" \t\r\n\v\f\"\'");
	std::size_t last_char = path.find_last_not_of(" \t\r\n\v\f\"\'");
	path = path.substr (first_char, (last_char - first_char + 1));
}


const std::string get_word ()
{
	
	std::cout << "Find: ";
	std::string input;
	std::getline (std::cin, input);
	
	input = input.substr (0, input.find (' '));
	
	return input;
}


const char get_input ()
{

	std::string input;
	
	do
	{
		
		std::cout << std::endl << "Examine another file? (y/n): ";
		std::getline (std::cin, input);
	} while (tolower (input[0]) != 'y' && tolower (input[0]) != 'n');
	
	return tolower (input[0]);
}


const int get_menu_input ()
{
	
	std::string input;
	
	do
	{
		
		std::cout << "Select an operation: " << std::endl << "\t1 - Display file statistics" << std::endl << "\t2 - List shortest words" << std::endl << "\t3 - List longest words" << std::endl << "\t4 - Search for a word" << std::endl << "\t5 - Exit" << std::endl;
		std::getline (std::cin, input);
	} while (isdigit (input[0]) && (int) input[0] > 0 && (int) input[0] < 6);
	
	std::cout << std::endl;
	
	return input[0] - '0';
}


const bool repeat ()
{
	
	return (get_input () == 'y' ? true : false);
}


std::string get_file_path (const char *program_name)
{
	
	std::string file_path;
	
	std::cout << "Enter a filename or absolute path: ";
	std::getline (std::cin, file_path);
	clean_path (file_path);
	if (is_filename (file_path))
	{
		
		/*WRAP IN TRY CATCH*/
		std::string file_name = file_path;
		
		file_path = program_name;
		std::size_t last_char = file_path.find_last_of (PATH_SEPERATOR);
		file_path = file_path.substr (0, (last_char));
		file_path.push_back (PATH_SEPERATOR);
		file_path.append (file_name);
		/*WRAP IN TRY CATCH*/
	}
	
	return file_path;
}


std::string file_statistics (DynamicArray &words, unsigned int &punctuation_chars)
{
	
	std::stringstream output;
	output << "Total number of words: " << words.get_data_length () - 1 << std::endl;
	//output << "Total characters: " << words.chars_count () << std::endl;
	output << "Average word length: " << ((float) words.chars_count ()/(words.get_data_length () - 1)) << std::endl;
	output << "Total number of punctuation characters: " << punctuation_chars << std::endl;
	output << "Shortest word length: " << words[0].length () << std::endl;
	output << "Longest word length: " << words[words.get_data_length () - 1].length () << std::endl;
	
	return output.str ();
}


int main (int argc, char const *argv[])
{
	
	std::cout << std::endl << "Project 1 from Assignment 4" << std::endl << "Text File Statistics" << std::endl << std::endl << "This program will receive a path to a text file and provide statistics about the words." << std::endl << std::endl;
	
	std::cout << "Please provide output file (will overwrite):" << std::endl;
	std::string output_file_path = get_file_path (argv[0]);
	std::ofstream output_file (output_file_path.c_str (), std::ofstream::trunc);
	
	std::cout << std::endl;
	
	std::string input_file_path;
	do
	{
		
		std::cout << "Please provide input file: " << std::endl;
		input_file_path = get_file_path (argv[0]);
		std::ifstream input_file (input_file_path.c_str());
		output_file << "Input file path: " << input_file_path << std::endl;
		
		if (!input_file.good ())
		{
			
			std::cout << "Error opening file at " << input_file_path <<". Double check file path." << std::endl;
			continue;
		}
		
		DynamicArray words;
		unsigned int punctuation_chars = 0;
		if (!populate_array (input_file, words, punctuation_chars))
		{
			
			std::cout << "Error reading file." << std::endl;
			continue;
		}
		
		input_file.close ();
		
		words.sort ();
		
		unsigned short int menu;
		do
		{
			
			output_file << std::endl << std::endl;
			
			menu = get_menu_input ();
			switch (menu)
			{
				
				case 1: //Statistics
				{
					std::string stats = file_statistics (words, punctuation_chars);
					std::cout << stats << std::endl;
					output_file << stats << std::endl;
				}
				break;
				
				case 2: //Shortest Words
				{
					
					std::string short_words = words.words_of_length (words[0].length (),'\n');
					std::cout << "Shortest words:" << std::endl << short_words << std::endl;
					output_file << "Shortest words:" << std::endl << short_words << std::endl;
				}
				break;
				
				case 3: //Longest Words
				{
					
					std::string longest_words = words.words_of_length (words[words.get_data_length () - 1].length (), '\n');
					std::cout << "Longest words:" << std::endl << longest_words << std::endl;
					output_file << "Longest words:" << std::endl << longest_words << std::endl;
				}
				break;
				
				case 4: //Search
				{
					
					std::string search_word = get_word ();
					unsigned int quantity_of_words = words.find_word (search_word);
					if (quantity_of_words > 0)
					{
						
						std::cout << search_word << " is used " << quantity_of_words << " time(s) in the file." << std::endl;
						output_file << search_word << " is used " << quantity_of_words << " time(s) in the file." << std::endl;
					} else {
						
						std::cout << search_word << " does not exist in file." << std::endl;
						output_file << search_word << " does not exist in file." << std::endl;
					}
					
				}
				break;
				
				default:
				break;
			}
		} while (menu != 5);
	} while (repeat ());
	
	output_file.close ();
	
	return 0;
}