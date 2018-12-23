import java.io.*;
import java.util.*;

public class Solution {
  // If you need extra classes, you can define them privately here within class Solution

  static void findFrequentEntries(List<List<String>> input) {
    // Your code here. Writes to standard output.
    // Format for output lines: "Name: 1230 1240 1245"
    Map<String, List<Integer>> map = new HashMap<>();
    Set<String> userNames = new HashSet<>();
    for(List<String> userEntry : input){
        String user = userEntry.get(0);
        Integer time = Integer.parseInt(userEntry.get(1));
        if(!map.containsKey(user)){
          List<Integer> userTimes = new ArrayList<>();
          userTimes.add(time);
          map.put(user, userTimes);
        }else{
          List<Integer> userTimes = map.get(user);
          userTimes.add(time);
          map.put(user, userTimes);
        }
      userNames.add(user);
    }
    
    Map<String, String> result = new HashMap<>();
    for(String user : userNames){
      List<Integer> userTimes = map.get(user);
      Collections.sort(userTimes);
      
      //actual logic to find employees who have accesstimes more than 3 time in 1 hour
      for(int j=0;j<userTimes.size();j++){
        int time = userTimes.get(j) + 100;
        int count = 1;
        for(int k=j+1;k<userTimes.size();k++){
          if(userTimes.get(k) <= time){
             count++;
          }
        }
        
        //output formatting
        if(count>=3 && !result.containsKey(user)){
          String out = user + ":";
          String times = "";
          int l = j;
          while(l<count+j){
            times += " ";
            times += String.valueOf(userTimes.get(l));
            l++;
          }
          out += times;
          result.put(user, out);
        }
      }
    }
    
    //To sort the users
    List<String> userList = new ArrayList<>();
    userList.addAll(userNames);
    Collections.sort(userList);
    
    if(result.size() == 0){
      System.out.println("None");
    }else{
      for(String user : userList){
        if(result.get(user) != null)
          System.out.println(result.get(user));
      }
    }
  }

  // DO NOT MODIFY MAIN()
  public static void main(String[] args) {
    List<List<String>> input = new ArrayList<List<String>>();

    String line;
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      while ((line = br.readLine()) != null) {
        if (line.equals("")) {
          continue;
        }

        List<String> pair = Arrays.asList(line.split(" "));
        input.add(pair);
        
      }
    } catch (IOException e) {
      e.printStackTrace();
      return;
    }

    findFrequentEntries(input);
  }
}
