#include <string>
using namespace std;


class Post {
	
	private:
	
		int post_id;
		int day , month , year;
		string post_title;
		string post_creator;
		string post_text;
	
	public:
	
	    Post(int , int , int , int , const string , const string , const string);	//initialise all class member variables
		Post(const Post&);															//copy constructor	
		~Post();
		
		void set_id(int);
		int get_id();

		void get_date(int& , int& , int&);
		void set_date(int d , int m , int y);  
		
		void set_title(const string);
		string get_title();
		
		void set_creator(const string);
		string get_creator();
		
		void set_text(const string);
		string get_text();
				
		void print_post();	//prints all class member variables
};





class Thread {
	
	private:
	
		string thread_subject;
		string thread_creator;
		int number_of_posts;		//Post objects in Thread
		int day , month , year;
		Post** post_pointer;		//pointer to ARRAY of pointers to Post objects
	
	public:
		
	    Thread(const string , const string , int , int , int , int);	//initialise all class member variables
		~Thread();
	
		void set_subject(const string);
		string get_subject();
	
		void set_creator(const string);
		string get_creator();
	
		void get_date(int& , int& , int&);
		void set_date(int d , int m , int y);  
	
		int get_number_of_posts();
		
		Post** get_post_pointer();
		
		void print_thread();			 //prints all Thread member variable and all its Posts
		void print_thread_subject();
		void print_thread_post(int);	//prints a Post with specific post_id if it exists
};





class ListNodePost {		//a node in a list of Posts

	private:

		ListNodePost* next;
		Post* post;

	public:

		ListNodePost(Post*);
		~ListNodePost();
		
		ListNodePost* get_next();
		void set_next(ListNodePost*);
		
		Post* get_post();
};





class TreeNode {		//node in a binary Tree that contains a list of posts for specific creator

	private:

		string creator;
		TreeNode* left_node_pointer;		//pointer to left child
		TreeNode* right_node_pointer;		//pointer to right child
		ListNodePost* root_post_pointer;	//pointer to the list of Posts

	public:

		TreeNode(Post*);			//created with one Post in its list
		~TreeNode();
		
		string get_creator();
		void set_creator(string);
		
		TreeNode* get_left_node_pointer();
		void set_left_node_pointer(TreeNode*);
		
		TreeNode* get_right_node_pointer();
		void set_right_node_pointer(TreeNode*);
		
		ListNodePost* get_root_post_pointer();
		void set_root_post_pointer(ListNodePost*);
		
		int get_list_post_number(ListNodePost*);
		
		ListNodePost* add_new_post_node(Post*,ListNodePost*);
		void print_list_nodes(ListNodePost*);
		void add_posts_to_array(Post**,int);
		Post** get_posts(ListNodePost*);
};





class Tree {		//manages a binary tree of TreeNodes with a pointer to its root
	
	private:
		
		TreeNode* root;
		
	public:
		
		Tree(Thread*);		//created for a specific Thread of the Forum
		~Tree();
		
		TreeNode* get_root();
		void set_root(TreeNode*);
		
		TreeNode* insert_tree_node(Post* , TreeNode*);
		void merge_tree(TreeNode* , TreeNode*);
		void print_tree(TreeNode*);
};





class Forum {		//contains a pointer to an ARRAY of pointers to Thread objects and a pointer to a Tree object
	
	private:
	
		string forum_title;
		int number_of_threads;
		Thread** thread_pointer;
		Tree* tree;
	
	public:
	 
	    Forum(const string);	//created with specific title and random size array of pointers to Thread objects that contain a random number of posts
		~Forum();
		
		void set_title(const string);
		string get_title();	
		
		void print_forum();						//prints all Thread subjects
		void print_forum_thread(const string);  //prints all Posts of a specific Thread
		void print_forum_post(int);				//prints one Post with specific post_id
		void print_sorted();					//prints all Forum Posts by creator alphabetically
};












