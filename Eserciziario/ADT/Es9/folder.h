#include "file.h"
typedef struct folder *Folder;

Folder newFolder();
void addFile(Folder folder, File file);
void removeFile(Folder folder, File file);
void printFolder(Folder folder);
void sortForName(Folder folder);
void sortForExtension(Folder folder);
File searchForName(Folder folder, char *name);
File searchForExtension(Folder folder, char *ext);