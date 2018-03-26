/*
    RUN: $valac --pkg gtk+-3.0 salut.vala
         $./salut     
**/
class Demo.Salut : GLib.Object{
    public static int main (string[] args){
        string text = "Salut, Romania!";
        stdout.printf(text + "\n");
        return 0;
    }
}
