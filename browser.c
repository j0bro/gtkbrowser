#include <stdio.h>
#include <signal.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <webkit/webkit.h>

void decorate();
void undecorate();
void maximize();
void unmaximize();

static WebKitWebView* web_view;
static GtkWidget *window;
static gboolean is_maximized;

gchar* default_url = "http://www.html5test.com";

int main(int argc, char** argv) {
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  web_view = WEBKIT_WEB_VIEW(webkit_web_view_new());

  WebKitWebSettings *settings = webkit_web_settings_new();
 //  g_object_set(G_OBJECT(settings), "enable-plugins", FALSE, NULL);

  webkit_web_view_set_settings(WEBKIT_WEB_VIEW(web_view), settings); 

  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(web_view));

  if(argc > 1) {
      webkit_web_view_open(web_view, argv[1]);
  }
  else {
      webkit_web_view_open(web_view, default_url);
  }

  decorate();
  unmaximize();
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

void decorate() {
  gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
}

void undecorate() {
  gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
}

void maximize() {
  gtk_window_maximize(GTK_WINDOW(window));
  gtk_window_fullscreen(GTK_WINDOW(window));

  is_maximized = true;
}

void unmaximize() {
  gtk_window_unmaximize(GTK_WINDOW(window));
  gtk_window_unfullscreen(GTK_WINDOW(window));
  gtk_window_resize(GTK_WINDOW(window), 800, 600);

  is_maximized = false;
}
