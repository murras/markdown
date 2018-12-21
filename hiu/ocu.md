
모바일 환경에서 데이터베이스 쓰기 위해 SQLite를 쓴다.

PC와 같은 개념.

데이터 관리를 한다. 데이터베이스 관리 시스템 or 소프트웨어

관계형 데이터베이스를 쓴다.

DBMS 데이터베이스를 관리하는 시스템. SQLite가 이에 속한다.

데이터 형식 문자, 숫자형

행 실제 데이터를 말한다.

SQLite는 기본적으로 설치되어 있다.

DB 생성 - 테이블 생성 - 데이터 입력 - 조회 및 활용

어플리케이션에서 활용하면 된다,

SQLiteOpenHelper 클래스를 상속받는 내부 클래스를 정의한다.

SQLiteDatabase 클래스를 통해 SQL문을 실행한다.

Cursor 인터페이스를 통해 커서를 이동하며 조회한다.

- SQLiteOpenHelper 클래스
  - onCreate() : 테이블 생성
  - onUpdate() : 테이블 삭제 후 다시 생성
  - getReadableDatabse() : 읽기 전용 DB 열기, SQLiteDatabase 반환
  - getWritableDatabase() : 읽기 쓰기 전용 DB 열기, SQLiteDatabase 반환
- SQLiteDatabase 클래스
  - execSQL() : SQL문 실행(Insert Update Delete)
  - close() : DB 닫기
  - query(), rawquery() : Select 실행 후 커서 반환
- Cursor 인터페이스
  - moveToFirst() : 커서의 제일 첫 행으로 이동
  - moveToLast() : 커서의 제일 마지막 행으로 이동
  - moveToNext() : 현재 커서의 다음 행으로 이동


- MainActivity 속에 내부 클래스로 생성한다.
- onCraete() 안에 생성한것이 아니다.
```java
public class myDB extends SQLiteOpenHelper {
    public myDB(Context context) {
        super(context, "human", null, 1) // 표준 커서시 null, version은 database 버전
    }
    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table ")
    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
        db.execSQL("DROP TABLE IF EXISTS MEMBER");
        onCreate();
    }
    @Override
    public void onClick(View v){
        sql = my.getReadableDatabase();
        Cursor cursor;        
    }
}
```
- DB 파일을 백업 받아야 한다. 실시간 조회를 할 수 없기 때문이다.
- Android Device Monitor - 기기 선택 - 다운받고 싶은 앱 패키지 주소를 찾는다.
- http://sqlitebroser.org
- Linear 기본값 horizontal
