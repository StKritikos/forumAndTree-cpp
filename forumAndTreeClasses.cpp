#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "forum_and_tree.h"
#include "helper.h" 
using namespace std;
using namespace Helper;




Post::Post (int n , int d , int m , int y , const string title , const string creator , const string text) {
	
	post_id = n;
	post_title = title;
	post_creator = creator;
	post_text = text;
	day = d;
	month = m;
	year = y;
	
	cout << "I just constructed a Post with title "<< post_title <<  " created by " << post_creator << " on " << day << "/" << month << "/" << year << " with text " << post_text << " and id " << post_id  << endl;
}

Post::Post(const Post &post) {    //copy constructor
	
	post_id = post.post_id;
	post_title = post.post_title;
	post_creator = post.post_creator;
	post_text = post.post_text;
	day = post.day;
	month = post.month;
	year = post.year;
} 
	
Post::~Post() {
	cout << "Post with id : " << post_id << " is about to be destroyed " << endl;
}

void Post::set_id(int id) {
	post_id = id;
}

int Post::get_id() {
	return post_id;
}

void Post::get_date(int &d , int &m , int &y) {
	d = day;
	m = month;
	y = year;
}

void Post::set_date(int d , int m , int y) {
	day = d;
	month = m;
	year = y;
}

void Post::set_title(const string title){
	post_title = title;
}

string Post::get_title(){
	return post_title;
}

void Post::set_creator(const string creator){
	post_creator = creator;
}

string Post::get_creator() {
	return post_creator;
}

void Post::set_text(const string text) {
	post_text = text; 
}

string Post::get_text() {
	return post_text;
}

void Post::print_post() {
	cout << "Post with id " << post_id << " created by " << post_creator << " on " << day << "/" << month << "/" << year << " contains text: " << post_text << endl ;
}






Thread::Thread (const string subject , const string creator , int posts , int d , int m , int y) {
	
	thread_subject = subject; 
	thread_creator = creator;
	number_of_posts = posts;
	day = d; 
	month = m;
	year = y;
	
	cout << "Thread with subject "<< thread_subject << " has just been created " << endl ;
	
	post_pointer = new Post* [number_of_posts];

		for (int i=0 ; i < number_of_posts ; i++)
			{
				int d =  1 + ( rand() % 30 );
				int m = 1 + ( rand() % 12 );
				int y = 2005 + ( rand() % ( 2019 - 2005 + 1 ) );
				int random_title_index = ( rand() % 10 );
				int random_creators_index = ( rand() % 7 );
				int random_text_index = ( rand() % 10 );
				post_pointer[i] = new Post(additive_post_id++ , d , m , y , random_title[random_title_index] , creators[random_creators_index], random_post_text[random_text_index]);
			}
}
	
Thread::~Thread() {
	
		for (int i=0 ; i < number_of_posts ; i++)
		{
			delete post_pointer[i];
		}
		delete post_pointer;
		
		cout << "Thread with subject " << thread_subject << " is about to be destroyed " << endl;
}

void Thread::set_subject(const string subject) {
	thread_subject = subject; 
}

string Thread::get_subject() {
	return thread_subject;
}

void Thread::set_creator(const string creator) {
	thread_creator = creator;
}

string Thread::get_creator() {
	return thread_creator;
}

int Thread::get_number_of_posts() {
	return number_of_posts;
}

Post** Thread::get_post_pointer() {
	return post_pointer;
}

void Thread::get_date(int &d , int &m , int &y) {
	d = day;
	m = month;
	y = year;
}

void Thread::set_date(int d , int m , int y) {
	day = d;
	month = m;
	year = y;
}

void Thread::print_thread() {
	cout << "Thread with subject " << thread_subject << " created on " << day << "/" << month << "/" << year << " from " << thread_creator << " has the following posts: " << endl; 
	
	for (int i=0; i < number_of_posts ; i++)
	{
		post_pointer[i] -> print_post();
	}
}

void Thread::print_thread_subject() {
	cout << "Thread's subject is " << thread_subject << endl;
}

void Thread::print_thread_post(int id) {
	for (int i=0 ; i < number_of_posts ; i++)
	{
		int check_id = post_pointer[i] -> get_id();
			if (id == check_id)
			{ 
				post_pointer[i] -> print_post();
				break;
			}
	}
}






ListNodePost::ListNodePost(Post* new_post) {	//class that contains a Post and a pointer to the next ListNodePost in order to create a list
	next = NULL;
	post = new Post(*new_post);
	cout << "ListNodePost created containing a post with creator " << post -> get_creator() << " and post ID : " << post -> get_id() << endl;
}

ListNodePost::~ListNodePost() {
	delete post;
	delete next;
    
	cout << "ListNodePost containing a post with creator " << post -> get_creator() << " and post ID : " << post -> get_id() << " was destroyed " << endl;
}

ListNodePost* ListNodePost::get_next() {   //returns a pointer to the next ListNodePost object in the list
	return next;
}

void ListNodePost::set_next(ListNodePost* pointer) {
	next = pointer;
}

Post* ListNodePost::get_post() {
	return post;
}







TreeNode::TreeNode(Post* post) {		//node in binary Tree for a unique Post creator with pointer for right/left child Node and pointer to the start of list of 
	
	creator = post -> get_creator();
	left_node_pointer = NULL;
	right_node_pointer = NULL;
	
	root_post_pointer = new ListNodePost(post); 	//pointer to the start of the list of ListNodePost 
	
	cout << "TreeNode for creator " << creator << " created " << endl;
}

TreeNode::~TreeNode() {

	delete left_node_pointer;
	delete right_node_pointer;
	delete root_post_pointer;

	cout << "TreeNode  for creator " << creator << " deleted " << endl;
}

void TreeNode::set_creator(string new_creator) {
	creator = new_creator;
}

string TreeNode::get_creator() {
	return creator;
}

TreeNode* TreeNode::get_left_node_pointer() {
	return left_node_pointer;
}

void TreeNode::set_left_node_pointer(TreeNode* pointer) { 
	left_node_pointer = pointer;
}

TreeNode* TreeNode::get_right_node_pointer() {
	return right_node_pointer;
}

void TreeNode::set_right_node_pointer(TreeNode* pointer) {
	right_node_pointer = pointer;
}

ListNodePost* TreeNode::get_root_post_pointer() {
	return root_post_pointer;
}

void TreeNode::set_root_post_pointer(ListNodePost* pointer) {
	root_post_pointer = pointer;
}

int TreeNode::get_list_post_number(ListNodePost* current_node) {
	int count = 0;
	while(current_node != NULL)
	{
		count = count + 1;
		current_node = current_node -> get_next();
	}
	return count;
}

void TreeNode::add_posts_to_array(Post** posts_array , int number_of_posts) {
	ListNodePost* node = this -> get_root_post_pointer();
	for(int i=0 ; i < number_of_posts ; i++)
	{
		posts_array[i] = new Post(*(node -> get_post()));
		node = node -> get_next();
	}
}

Post** TreeNode::get_posts(ListNodePost* root) {
	int number_of_posts = this -> get_list_post_number(root);
	Post** post_array = new Post*[number_of_posts];
	this -> add_posts_to_array(post_array , number_of_posts);
	return post_array;
}

ListNodePost* TreeNode::add_new_post_node(Post* post , ListNodePost* current_node) {
	
	if(current_node == NULL)
	{
		current_node = new ListNodePost(post);
	}
	else
	{
		current_node -> set_next(add_new_post_node(post , current_node -> get_next()));
	}
	return current_node;
}

void TreeNode::print_list_nodes(ListNodePost* current_node) {
	
	if(current_node == NULL)
	{
		return;
	}
	current_node -> get_post() -> print_post();
	print_list_nodes(current_node -> get_next());	
}






Tree::Tree (Thread* thread) {		//contains pointer to binary Tree for a given Thread , with a list of Posts of each creator in each TreeNode
	
	Post** post_pointer = thread -> get_post_pointer();		//get access to Thread's Posts
	int number_of_posts = thread -> get_number_of_posts();  
	
	root = new TreeNode(post_pointer[0]);	//creates the root TreeNode of the binary Tree
	
	for(int i=1 ; i < number_of_posts ; i++)	//for each Post in the Thread
	{
		insert_tree_node(post_pointer[i] , root); 	//create a new TreeNode if Post creator does not exist in the Tree OR place the Post in existing TreeNode  
	}
	
	cout << "Tree created for Thread with subject " << thread -> get_subject() <<  endl;
}

Tree::~Tree () {
	delete root;
	cout << "Tree deleted" << endl;
}

TreeNode* Tree::insert_tree_node(Post* post , TreeNode* current_node) {	//make a new treeNode if (creator of Post)!=(creator if TreeNode)
	if(current_node == NULL)											//of add the post in the list if (creator of Post)=(creator if TreeNode)
	{
		current_node = new TreeNode(post);
		return current_node;
	}
	else
	{
		string post_creator = post -> get_creator();
		
		if(post_creator == current_node -> get_creator())
		{
			current_node -> add_new_post_node(post , current_node -> get_root_post_pointer());
			return current_node;
		}
		else if(current_node -> get_creator().compare(post_creator) > 0)
		{
			current_node -> set_left_node_pointer(insert_tree_node(post , current_node -> get_left_node_pointer()));
		}
		else
		{
			current_node -> set_right_node_pointer(insert_tree_node(post , current_node -> get_right_node_pointer()));
		}
		return current_node;	
	}		
}

void Tree::merge_tree(TreeNode* current_node , TreeNode* current_node2){
	if(current_node2 -> get_left_node_pointer() != NULL)
	{
		merge_tree(current_node , current_node2 -> get_left_node_pointer());
	}

	int number_of_posts = current_node2 -> get_list_post_number(current_node2 -> get_root_post_pointer());	//get array of posts of current_node2
	Post** array = current_node2 -> get_posts(current_node2 -> get_root_post_pointer());
	
	for(int i=0 ; i < number_of_posts ; i++)
	{
		insert_tree_node(array[i] , current_node);
	}
	
	for(int j=0 ; j < number_of_posts ; j++)
	{
		delete array[j];
	}
	delete array;
	
	if(current_node2 -> get_right_node_pointer() != NULL)
	{
		merge_tree(current_node , current_node2 -> get_right_node_pointer());
	}		
}

void Tree::print_tree(TreeNode* current_node) {
	if(current_node -> get_left_node_pointer() != NULL)
	{
		print_tree(current_node -> get_left_node_pointer());
	}
	cout << "Tree Node with creator "<< current_node -> get_creator() << " and posts: " << endl;
	
	current_node -> print_list_nodes(current_node -> get_root_post_pointer());
	if(current_node -> get_right_node_pointer() != NULL)
	{
		print_tree(current_node -> get_right_node_pointer());
	}
}

TreeNode* Tree::get_root() {
	return root;
}

void Tree::set_root(TreeNode* new_root) {
	root = new_root;
}







Forum::Forum (const string title ) {
	
	srand ( time(NULL) );
	
	forum_title = title;
	number_of_threads = 2 + ( rand() % 10 );		     //toulaxiston 2 Thread
	thread_pointer = new Thread* [number_of_threads];
	
	cout << "Forum with title "<< forum_title << " has just been created " << "\n"<<  endl;
	
	int day = 1 + ( rand() % 30 );						//create random values for Thread "Kanones kai xrisimes plirofories"	
	int month = 1 + ( rand() % 12 );
	int year = 2005 + ( rand() % ( 2019 - 2005 + 1 ) );
	int random_creator = ( rand() % 7 );
	int random_number_of_posts = 1 + ( rand() % 5 );
	
	thread_pointer[0] = new Thread("Kanones_kai_xrisimes_plirofories" , creators[random_creator] , random_number_of_posts , day , month , year );
		
		for (int i=1 ; i < number_of_threads ; i++)
			{
				day = 1 + ( rand() % 30 );							//random values for the rest of the Threads
				month = 1 + ( rand() % 12 );
				year = 2005 + ( rand() % ( 2019 - 2005 + 1 ) );
				int random_creator = ( rand() % 7 );
				int random_thema = ( rand() % 10 );
				int random_number_of_posts = 1 + ( rand() % 5 );
				thread_pointer[i] = new Thread(random_subject[random_thema] , creators[random_creator] , random_number_of_posts , day , month , year);
			}
}
	
Forum::~Forum(){
	
		for (int i=0 ; i < number_of_threads ; i++)
		{
			delete thread_pointer[i] ;
		}
		delete thread_pointer;
		delete tree;
		
		cout << "Forum with title " << forum_title << " is about to be destroyed " << endl;
}

void Forum::set_title(const string title) {
	forum_title = title; 
}

string Forum::get_title() {
	return forum_title;
}

void Forum::print_forum() {							//prints all Thread subjects of the Forum
	for (int i=0 ; i < number_of_threads ; i++)
	{
		thread_pointer[i] -> print_thread_subject();
	}
}

void Forum::print_forum_thread(const string subject ) {		//prints all Posts of a specific Thread
	for (int i=0 ; i < number_of_threads ; i++)
	{
		string check_subject;
		check_subject = thread_pointer[i] -> get_subject();
			if (check_subject == subject)
				{
					thread_pointer[i] -> print_thread();
					break;
				}
	}
}

void Forum::print_forum_post(int id) {				//prints a Post with specific post_id
	for (int i=0 ; i < number_of_threads ; i++)
	{
		thread_pointer[i] -> print_thread_post(id);
	}
}

void Forum::print_sorted() {					//prints all Forum Posts by creator alphabetically using inorder traversal
	tree = new Tree(thread_pointer[0]);			//creates a binary Tree for a given Thread with each TreeNode containing a list of Posts of a different creator
												//tree is a pointer to that binary Tree object
	cout << "Merging trees " << endl;
	
	for (int i=1 ; i < number_of_threads ; i++)								//for each Thread other than the first
	{		
		Tree* new_tree = new Tree(thread_pointer[i]);						//create a binary Tree
		tree -> merge_tree(tree -> get_root() , new_tree -> get_root());	//and merge it into the first one
		delete new_tree;													//delete second Tree after merging with the first
	}
	cout << "Printing all Posts alphabetically by each creator (printing the tree) " << endl;
	tree -> print_tree(tree -> get_root());
}




















