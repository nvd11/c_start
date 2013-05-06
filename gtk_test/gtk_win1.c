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
//void gtk_hello1(void);
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
//void gtk_hello1(){
	g_print("Hello World\n");
}

/*
 * if your "delete_event" function return C_FALSE, GTK will sentout "destroy" signal
 * if you dont wanna to close the windows, let it return C_TRUE,
 * It's useful when your want it to show dailog msg with "Do you want to exit?"
 */
gint delete_event_01(GtkWidget * widget, GdkEvent * event, gpointer data){
	g_print("delete event occrred\n");
	//return C_FALSE then the program will exit
	return FALSE;
}

/* another call-back function */
void destroy_01(GtkWidget * widget, gpointer data){
	gtk_main_quit();
}

/* a window with an exit-button */
int gtk_win_02(int argc, char *argv[]){
	// GtkWidget is the type of Componet
	GtkWidget * window;
	GtkWidget * button;

	//this function is necessary for all gtk programs.
	gtk_init(&argc, &argv);

	//init a new window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/*
	 *  when the window receive a signal of "detele_event"
	 * (this signal is sent by window-manager, usually it's caused by "close the window"
	 * or clicking the close-button on the menubar)
	 * we will let it call the function "delete_event" defined above
	 * it will sent NULL to the parameter "data", it will be ignored by the function
	 */
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event_01),NULL);

	/*
	 *  here we connect the event "destroy" to another signal-handle function
	 * call function gtk_widget_destroy() for this window or return FALSE in function delete_event()
	 * will trigger this event
	 */
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy_01),NULL);

	//set the width of window
	gtk_container_set_border_width(GTK_CONTAINER(window), 100);

	//create an button with label "Hello world"
	button = gtk_button_new_with_label ("Hello World");

	/*
	 * when button receive the signal of "clicked", we let it call function gtk_hello1() defined above
	 * and sent NULL for it's parameter
	 */
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_hello1), NULL);

	/*
	 * when click the button, we will let it call gtk_widget_destroy(window) to close
	 * the window, signal "destroy" will sent out from here or from window-manager
	 * and then it will call destroy01();
	 */
	g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), window);

	/*
	 * put this button to the window
	 */
	gtk_container_add(GTK_CONTAINER(window), button);

	/*
	 * here show the button and the window..
	 */
	gtk_widget_show(button);
	gtk_widget_show(window);

	/*
	 * all the gtk program need this funtion gtk_main(). program will standby here
	 * and wait the signal sent out( ex by keyboard or mouse)
	 */
	gtk_main();
	return 0;
}
