/*
    AUTHOR:     Mihai Cornel mhcrnl@gmail.com
    DATE:       26.03.2018
    COMPILE:    $valac --pkg gtk+-3.0 salut.vala
    RUN:        $./salut     
**/
public class Aplicatia : Gtk.Application {

    protected override void activate() {
        var window = new Gtk.ApplicationWindow(this);
        var label =  new Gtk.Label("Prima aplicatie Vala");
        window.add(label);
        window.set_title("Fereastra aplicatiei Vala");
        window.set_default_size(400,400);
        window.show_all();
    }
}
public static int main (string[] args){
        //string text = "Salut, Romania!";
        //stdout.printf(text + "\n");
        return new Aplicatia().run(args);
}

