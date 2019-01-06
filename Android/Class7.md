- Thread
- AsyncTask
- Logging

## Thread
- 작업의 흐름
- 기본적으로 main 혹은 UI Thread가 존재한다.
- 일반적으로 하나의 Thread로 처리가 가능하나, 많고 무거운 일을 분할하여 Multi Thread로 처리하면 일을 가볍고 빠르게 처리 가능하다.
- 무작정 늘리기엔 한계가 있다.

### Android Threading
#### UI Thread가 필수적으로 하는 작업
- UI Drawing
- Touch Event
#### 그 외 사용자 정의 작업
- Huge Calculation
- Internet

- *안드로이드는 5초 이상 갱신되지 않으면 종료된다.*

### Thread 구현법
- Java의 Thread와 Android의 Handler를 이용해서 Thread를 구현할 수 있다.
- 다른 방법으로는 AsyncTask라는 Class를 이용해서 Thread와 Handler를 구현할 수 있다. 

- 공식 문서 참고 : https://developer.android.com/guide/components/processes-and-threads?hl=ko#Threads
- YouTube 참고 : https://www.youtube.com/watch?v=0Z5MZ0jL2BM

## AsyncTask
- 실습을 통해 사용법을 익히자.
- 공식 문서 참고 : https://developer.android.com/intl/ko/reference/android/os/AsyncTask.html
- 참고 https://realm.io/kr/news/android-thread-looper-handler/

## Logging
- `Log.d(Tag, Message);`

## Debug

## Image Library
- HTTP Client 기능 : 서버에서 이미지를 다운로드 받아서 사용해야한다.
- 캐싱 : 다시 불러오지 않아야 한다.
- 이미지 처리 : 고해상도 이미지를 줄여서 메모리를 효율적으로 쓸 수 있어야 한다.
- Glide, Volley, AUIL, Picasso를 써서 이용가능하다.
- Glide 참고 사이트
  - https://github.com/bumptech/glide
  - https://d2.naver.com/helloworld/429368
  - http://gun0912.tistory.com/17


- 실습 1(AsyncTask, Log, Debug)
> MainActivity.java
```java
package com.example.t717.class7_c_asynccalculation;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView tvDisplay;

    // Logging

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvDisplay = (TextView) findViewById(R.id.tv_display);
        findViewById(R.id.btn_start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startAsyncCalculation();
            }
        });
    }

    private void startAsyncCalculation() {
        // execute(1, 100_000_000)
        AsyncCalculateTask task = new AsyncCalculateTask();
        // task.execute(1, 100_000_000);
        task.execute(1, Integer.MAX_VALUE);
    }

    /**
     * <Input, Ing, Output>
     */
    class AsyncCalculateTask extends AsyncTask<Integer, Integer, Integer> {
        /**
         * UI Thread(실행 전)
         */
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        /**
         * Async Thread Method
         */
        @Override
        protected Integer doInBackground(Integer... integers) {
            int number = integers[0];
            int count = integers[1];
            int result = 0;
            int percentUnit = count / 100;
            for (int i = 0; i < count; i++) {
                result += number;
                if (result % percentUnit == 0) {
                    // 1% 2% .... 15% ...
                    publishProgress(result / percentUnit);
                }
            }
            return result;
        }

        /**
         * UI Thread (진행 상황)
         */
        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);
            tvDisplay.setText(values[0] + " Percent");
            Log.d("AsyncCalculateTask", values[0]+" Percent");
        }

        /**
         * UI Thread (끝나고 난 뒤 실행)
         */
        @Override
        protected void onPostExecute(Integer integer) {
            super.onPostExecute(integer);
            tvDisplay.setText("Result : " + integer);
        }
    }
}
```


> activity_main.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="16dp"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/tv_display"
        android:textSize="24sp"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World!"
        />
    <Button
        android:id="@+id/btn_start"
        android:text="Start"
        android:layout_width="match_parent"
        android:layout_height="wrap_content" />


</LinearLayout>
```

- 실습 2
> MainActivity.java
```java
package com.example.t717.class7_g_ireneglide;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import com.bumptech.glide.Glide;

public class MainActivity extends AppCompatActivity {
    ImageView ivIrene;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ivIrene = (ImageView) findViewById(R.id.iv_irene);
        findViewById(R.id.btn_start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startLoadingIreneImage();
            }
        });
    }

    private void startLoadingIreneImage() {
        String url = "http://cphoto.asiae.co.kr/listimglink/1/2018031618193283914_1521191973.jpg";
        Glide.with(this).load(url).into(ivIrene);
    }
}
```


> activity_main.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    tools:context=".MainActivity">

    <ImageView
        android:id="@+id/iv_irene"
        android:layout_width="match_parent"
        android:layout_height="300dp"
        />
    <Button
        android:id="@+id/btn_start"
        android:text="IRENE!!!"
        android:layout_width="match_parent"
        android:layout_height="wrap_content" />
</LinearLayout>
```