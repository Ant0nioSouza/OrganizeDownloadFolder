package br.com.antoniosouza;

import java.io.File;
import java.util.Arrays;

public class main {
    public static void main(String[] args) {
        String[] extensions = new String[]{".pdf", ".txt", ".log", ".tgz", ".m4a", ".jar", ".jar", ".7z", ".tar.gz", ".mp4", ".rar", ".zip", ".jpg", ".png", ".jpeg", ".pptx", ".docx", ".java", ".dat", ".exe", ".mp3", ".htm", ".tflite"}; // File extensions array

        String home = System.getProperty("user.home");
        System.out.println(home);
        String path = home + "\\Downloads";
        File files = new File(path);
        File[] list = files.listFiles();
        System.out.println(Arrays.toString(list));
        for (File file : list) {
            String fileName = file.getName();
            for (String extension : extensions) {
                File extensionDirectory = new File(home + "\\Downloads\\" + extension);
                File directoryToExtensionFile = new File(String.valueOf(extensionDirectory) + "\\" + fileName);
                File otherDirectory = new File(home + "\\Downloads\\others");
                File directoryToOtherFile = new File(String.valueOf(otherDirectory) + "\\" + fileName);
                if (fileName.endsWith(extension)) {
                    if (extensionDirectory.isDirectory()) {
                        file.renameTo(new File(String.valueOf(directoryToExtensionFile)));
                        System.out.println(file + " moved to " + directoryToExtensionFile);
                    } else {
                        extensionDirectory.mkdir();
                        file.renameTo(new File(String.valueOf(directoryToExtensionFile)));
                    }
                } else {
                    System.out.println(fileName);
                    if (otherDirectory.isDirectory()) {
                        if (!file.isDirectory()) {
                            file.renameTo(new File(String.valueOf(directoryToOtherFile)));
                        }
                    } else {
                        if (!file.isDirectory()) {
                            otherDirectory.mkdir();
                            file.renameTo(new File(String.valueOf(directoryToOtherFile)));
                        }
                    }
                }
            }

        }
    }
}
