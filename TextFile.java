package Lab_9;

public class TextFile {
    private File name;
    private Directory directory;
    private String content = "";

    public TextFile(File name, Directory directory){
        this.name = name;
        this.directory = directory;
    }

    public void rename(String name_2){
        name.changeName(name_2);
    }

    public void add_text(String text){
        content += text;
    }

    public String get_text(){
        return content;
    }

    public String getName(){
        return name.getName();
    }

}
