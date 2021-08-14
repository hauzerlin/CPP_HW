
void Push(queue_post & Queue, std::string temp);
void Display(queue_post & Queue);
void Post_Links_Build(queue_post &Queue, std::string first_line, int size);
//void Post_Links_Build(queue_post &Queue, string first_line, int size);


queue_post Read_file(TreeNodePtr * root, char **filename);
void Save_tree_toFile(TreeNodePtr *root, char *filename);
void Write_file(TreeNodePtr *root, std::ofstream outfile);
void Write_to_file(queue_post &Queue, std::ofstream *out);
