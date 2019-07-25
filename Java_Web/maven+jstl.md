### 프로젝트 만들기
![Image](https://i.imgur.com/CnAZb6s.png)
![Image](https://i.imgur.com/zQu0Eur.png)
![Image](https://i.imgur.com/fEHVQST.png)


### `pom.xml` 수정.
```xml
<dependency>
    <groupId>javax.servlet</groupId>
    <artifactId>jstl</artifactId>
    <version>1.2</version>
</dependency>
```


### `web.xml` 싹 다 지우고 아래 내용으로 변경.
```xml
<?xml version="1.0" encoding="UTF-8"?>
 
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://xmlns.jcp.org/xml/ns/javaee"
    xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_3_1.xsd"
    version="3.1">
    <display-name>Archetype Created Web Application</display-name>
</web-app>
```


### [jstl-1.2.jar 다운로드 링크](http://www.java2s.com/Code/Jar/j/Downloadjstl12jar.htm)에 들어가서 다운을 받고, Tomcat 경로의 `lib/` 안에 넣는다.


### jstl을 사용한 jsp 파일 작성
```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %> 
<%
request.setAttribute("A", 0);
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<c:if test="${n == 0}">
A는 0이다.
</c:if>

<c:if test="${n != 0}">
A는 0이 아니다.
</c:if>
</body>
</html>
```


### 서버에서 실행
![Image](https://i.imgur.com/ia8A8LF.png)

![Image](https://i.imgur.com/gI3HwrM.png)