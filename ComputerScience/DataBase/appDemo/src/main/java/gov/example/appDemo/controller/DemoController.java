package gov.example.appDemo.controller;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import java.io.IOException;
import java.sql.*;
import java.util.Iterator;

@Controller
@RequestMapping("/students")
@ResponseBody

//Class
public class DemoController {
	Connection conn;
	
	PreparedStatement pstmt = null;
	
	public DemoController() throws Exception
	{
		String url = "jdbc:postgresql://localhost/hongik?user=postgres&password=1234";
		conn = DriverManager.getConnection(url);
		
		//checkTable();
		ReadDataFromHomepage();
	}
	
	public void checkTable() throws Exception{
		DatabaseMetaData metadata = conn.getMetaData();
		
		ResultSet resultSet = metadata.getTables(null, null, "students", null);
		
		// 기존에 테이블이 있으면 테이블 드랍
		if(resultSet.next()) {
			String sql = "DROP TABLE students";
			pstmt = conn.prepareStatement(sql);
			pstmt.executeUpdate();
		}
		
		// 내 테이블 생성
		String sql1 = "CREATE TABLE IF NOT EXISTS students (name VARCHAR(100), email VARCHAR(100), degree VARCHAR(20), graduation INTEGER, PRIMARY KEY (email))";
		pstmt = conn.prepareStatement(sql1);
		pstmt.executeUpdate();
	}
	
	public void ReadDataFromHomepage() throws Exception {
		String myURL = "https://apl.hongik.ac.kr/lecture/dbms";
		
		try {
			Document doc = Jsoup.connect(myURL).get();
			
			// 크롤링!
			Elements PMUSelect = doc.select(".yaqOZd h2");
			
			String[] PMUArray = new String[3];
			Integer cnt = 0;
			
			System.out.println("=========================================");
			
			Iterator<Element> PMUIter = PMUSelect.iterator();
			
			while (PMUIter.hasNext()) {
				String myDegree = PMUIter.next().text();
				String[] temp = myDegree.split(" Students");
				String temp1 = temp[0].toLowerCase();
				if (temp1.equals("undergraduate"))
					temp1 = "undergrad";
				PMUArray[cnt] = temp1;
				cnt++;
				System.out.println(temp[0]);
			}
			
			Elements myElement = doc.select(".yaqOZd ul");

			Element[] splitGrad = new Element[3];
			
			Iterator<Element> ie = myElement.iterator();
			
			int i = 0;
			
			while(ie.hasNext()) {
				splitGrad[i] = ie.next();
				i++;
			}
			
			Elements phdElement = splitGrad[0].select("li");
			Elements masterElement = splitGrad[1].select("li");
			Elements undergradElement = splitGrad[2].select("li");			
			
			System.out.println("=========================================");
			
			Iterator<Element> ie1 = phdElement.iterator();
			
			// PhD 크롤링
			while (ie1.hasNext()) {
				String temp1 = ie1.next().text();
				String[] splitData = temp1.split(", ");
				String name = splitData[0];
				String email = splitData[1];
				String graduation = splitData[2];
				// String PhD가 아닌, 웹에서 직접 PhD 가져오기
				String degree = PMUArray[0];
				Integer intGraduation = Integer.parseInt(graduation);
				
				// 이미 email이 같은 사람이 있으면, 크롤링된 데이터가 들어가지 않도록 함
				String sqlCheck = "SELECT s.email FROM students s WHERE s.email = ?";
				pstmt = conn.prepareStatement(sqlCheck);
				pstmt.setString(1, email);
				ResultSet rs = pstmt.executeQuery();
				
				Integer count = 0;
				
				while(rs.next()) {
					count++;
				}
				
				if (count >= 1) {
					System.out.println("Already registered");
					continue;
				}
				
				String sql = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, name);
				pstmt.setString(2, email);
				pstmt.setString(3, degree);
				pstmt.setInt(4, intGraduation);
	            int result = pstmt.executeUpdate();
	            if(result ==1) System.out.println("inset 저장 성공!");
	            else System.out.println("저장 실패");
				System.out.println(temp1);
			}
			
			System.out.println("=========================================");
			Iterator<Element> ie2 = masterElement.iterator();
			
			// Master 크롤링!
			while (ie2.hasNext()) {
				String temp2 = ie2.next().text();
				String[] splitData = temp2.split(", ");
				String name = splitData[0];
				String email = splitData[1];
				String graduation = splitData[2];
				// String Master가 아닌, 웹에서 직접 Master 가져오기
				String degree = PMUArray[1];
				Integer intGraduation = Integer.parseInt(graduation);
				
				String sqlCheck = "SELECT s.email FROM students s WHERE s.email = ?";
				pstmt = conn.prepareStatement(sqlCheck);
				pstmt.setString(1, email);
				ResultSet rs = pstmt.executeQuery();
				
				Integer count = 0;
				
				while(rs.next()) {
					count++;
				}
				
				if (count >= 1) {
					System.out.println("Already registered");
					continue;
				}
				
				String sql = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, name);
				pstmt.setString(2, email);
				pstmt.setString(3, degree);
				pstmt.setInt(4, intGraduation);
	            int result = pstmt.executeUpdate();
	            if(result ==1) System.out.println("inset 저장 성공!");
	            else System.out.println("저장 실패");
				System.out.println(temp2);
			}
			
			System.out.println("=========================================");
			Iterator<Element> ie3 = undergradElement.iterator();
			
			// Undergrad 크롤링!
			while (ie3.hasNext()) {
				String temp3 = ie3.next().text();
				String[] splitData = temp3.split(", ");
				String name = splitData[0];
				String email = splitData[1];
				String graduation = splitData[2];
				// String Undergraduate가 아닌, 웹에서 직접 Undergraduate 가져오기
				String degree = PMUArray[2];
				Integer intGraduation = Integer.parseInt(graduation);
				
				String sqlCheck = "SELECT s.email FROM students s WHERE s.email = ?";
				pstmt = conn.prepareStatement(sqlCheck);
				pstmt.setString(1, email);
				ResultSet rs = pstmt.executeQuery();
				
				Integer count = 0;
				
				while(rs.next()) {
					count++;
				}
				
				if (count >= 1) {
					System.out.println("Already registered");
					continue;
				}
				
				String sql = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, name);
				pstmt.setString(2, email);
				pstmt.setString(3, degree);
				pstmt.setInt(4, intGraduation);
	            int result = pstmt.executeUpdate();
	            if(result ==1) System.out.println("inset 저장 성공!");
	            else System.out.println("저장 실패");
				System.out.println(temp3);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	@GetMapping("/degree")
	@ResponseBody
	public String getDegree (@RequestParam("name") String name) throws Exception {
		String result = new String();
		
		String sql = "SELECT s.degree FROM students s WHERE s.name = ?";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, name);
		ResultSet rs = pstmt.executeQuery();
		
		Integer count = 0;
		
		while(rs.next()) {
			result = name + " : " + rs.getString("degree");
			++count;
		}
		
		if (count == 0)
			return "No such student";
		else if (count == 1)
			return result;
		else {
			return "There are multiple students with the same name. Please provide an email address instead.";
		}
	}
	
	@GetMapping("/email")
	@ResponseBody
	public String getEmail (@RequestParam("name") String name) throws Exception {
		String result = new String();
		
		String sql = "SELECT s.email FROM students s WHERE s.name = ?";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, name);
		ResultSet rs = pstmt.executeQuery();
		
		Integer count = 0;
		
		while(rs.next()) {
			result = name + " : " + rs.getString("email");
			++count;
		}
		
		if (count == 0)
			return "No such student";
		else if (count == 1)
			return result;
		else {
			return "There are multiple students with the same name. Please contact the administrator by phone.";
		}
	}
	
	@GetMapping("/stat")
	@ResponseBody
	public String getStat (@RequestParam("degree") String degree) throws Exception {
		String result = new String();
		
		String sql = "SELECT s.degree, count(*) AS cnt FROM students s GROUP BY s.degree HAVING s.degree = ?";
		pstmt = conn.prepareStatement(sql);
		
		pstmt.setString(1, degree);
		ResultSet rs = pstmt.executeQuery();
		
		while(rs.next()) {
			result = rs.getString("cnt");
		}
		
		return "Number of " + degree + "'s student : " + result;
	}
	
    @PutMapping("/register")
	@ResponseBody
	public String putRegister (@RequestParam("name") String name, @RequestParam("email") String email, @RequestParam("degree") String degree, @RequestParam("graduation") Integer graduation) throws Exception
	{	
		String sql = "SELECT s.email FROM students s WHERE s.email = ?";
		pstmt = conn.prepareStatement(sql);
		pstmt.setString(1, email);
		ResultSet rs = pstmt.executeQuery();
		
		String sql1 = "SELECT s.name FROM students s WHERE s.name = ?";
		pstmt = conn.prepareStatement(sql1);
		pstmt.setString(1, name);
		ResultSet rs1 = pstmt.executeQuery();
		
		Integer count = 0;
		
		
		
		while(rs.next()) {
			count++;
		}
		
		while(rs1.next()) {
			count++;
		}
		
		if (count >= 1) {
			return "Already registered";
		}
		else {
			String sql2 = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
			pstmt = conn.prepareStatement(sql2);
			
			pstmt.setString(1, name);
			pstmt.setString(2, email);
			pstmt.setString(3, degree);
			pstmt.setInt(4, graduation);
            int resultInsert = pstmt.executeUpdate();
            
            if(resultInsert == 1) System.out.println("inset 저장 성공!");
            else System.out.println("저장 실패");
			
			return "Registration successful";
		}
	}
}