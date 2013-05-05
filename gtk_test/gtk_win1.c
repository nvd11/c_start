/*
 * gtk_win1.c
 *
 *  Created on: 2013-5-5
 *      Author: gateman
 */
#include "gtk_win1.h"
#include <stdio.h>
#include <gtk/gtk.h>

int gtk_win_01(int, char **);
int gtk_win_02(int, char **);
void gtk_hello1(GtkWidget * , gpointer );
gint delete_event(GtkWidget *, GdkEvent *, gpointer);

int gtk_win1(int argc, char * argv[]){
	//gtk_win_01(argc, argv);
	gtk_win_02(argc, argv);
	return 0;
}

int gtk_win_01(int argc, char * argv[]){
	int i;
	printf("gtk_win1 start\n");
	printf("argc is %d\n", argc);
	for (i=0; i<= argc -1; i++){
		printf("the %dth parameter is: %s\n",i,argv[i]);
	}

	GtkWidget * window;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}

void gtk_hello1(GtkWidget * widget, gpointer data){
	g_print("Hello World\n");
}

/*
 * if your "delete_event" function return C_FALSE, GTK will sentout "destroy" signal
 * if you dont wanna to close the windows, let it return C_TRUE,
 * It's useful when your want it to show dailog msg with "Do you want to exit?"
 */
gint delete_event(GtkWidget * widget, GdkEvent * event, gpointer data){
	g_print("delete event occrred\n");
	//return C_FALSE then the program will exit
	return TRUE;
}

int gtk_win_02(int artc, char *argv[]){
	return 0;
}
