- 계정 생성
    - `CREATE USER __ID__ IDENTIFIED BY __Password__;`
- 방금 만든 계정으로 로그인을 하면 `ORA-01045 : user __ID__ lacks CREATE SESSION privilege; logon denied` 오류가 발생할 것이다.
    - `grant connnect, resoure to __ID__;`
  