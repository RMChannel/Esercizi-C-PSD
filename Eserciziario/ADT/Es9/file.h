typedef struct file *File;
File newFile(char *name, char *extension, float dim);
int controlName(File f1, File f2);
int controlExtension(File f1, File f2);
void printFile(File f);