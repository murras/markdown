- Collections
- ArrayList
- RecyclerView
- ViewHolder
- RecyclerView.Adapter
## Data to Object
## Collections
- ArrayList를 이용한다.
- `ArrayList<DataUserPost> arrayList = new ArrayList<>();`
- `arrayList.add(1, new DataUserPost());`
- `arrayList.remove(1);`
- 순회법 2가지
```java
for(int i = 0; i < arrayList.size(); i++) {
    DataUserPost data = arrayList.get(i);
    System.out.println(data.toString());
```
```java
for(DataUserpost data : arrayList) {
    System.out.println(data.toString());
}
```
## RecyclerView, ViewHolder
- `findViewById`는 비용이 큰 메소드이기 때문에 Caching하기 위해 ViewHolder를 사용한다.

## RecyclerView.Adapter
- `Adapter<ViewHolder>` : <> 안에 자신이 정의한 뷰홀더를 넣거나 여러 형태의 뷰를 넣고 싶다면 <RecyclerView.ViewHolder>를 넣으면 된다.
- `onCreateViewHolder`, `onBindViewHolder`, `getItemCount`는 반드시 구현해야한다.

- 실습 1(ArrayList)
> MainActivity.java
```java
package com.example.t717.class6_c;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.example.t717.class6_c.model.PostItem;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayList<PostItem> listItem = new ArrayList<>();
        LinearLayout llScrollParent = (LinearLayout) findViewById(R.id.ll_scroll);*/
        for (int i = 0; i < 30; i++) {
            PostItem item = new PostItem("http://cphoto.asiae.co.kr/listimglink/1/2018031618193283914_1521191973.jpg"
                    , "irene", "wow !!", 125, true);
            listItem.add(i, item);
        }
    }
}
```

> PostItem.java
```java
package com.example.t717.class6_c.model;

public class PostItem {
    String postImgUrl;
    String userName;
    String postText;
    int postLikeCount;
    boolean isUserLike;

    public PostItem(String postImgUrl, String userName, String postText, int postLikeCount, boolean isUserLike) {
        this.postImgUrl = postImgUrl;
        this.userName = userName;
        this.postText = postText;
        this.postLikeCount = postLikeCount;
        this.isUserLike = isUserLike;
    }

    public String getPostImgUrl() {
        return postImgUrl;
    }

    public String getUserName() {
        return userName;
    }

    public String getPostText() {
        return postText;
    }

    public int getPostLikeCount() {
        return postLikeCount;
    }

    public boolean isUserLike() {
        return isUserLike;
    }
}
```

> post_item.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:padding="16dp"
    android:orientation="vertical">
    
    <TextView
        android:textColor="#6200ea"
        android:text="ansta_"
        android:id="@+id/tv_UserName"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />
    <TextView
        android:layout_marginLeft="8dp"
        android:text="불꽃놀이했어요~"
        android:id="@+id/tv_PostText"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

</LinearLayout>
```

- 실습 2(RecyclerView, Adapter)
> like_buttom.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<selector xmlns:android="http://schemas.android.com/apk/res/android">
    <item android:drawable="@drawable/heart_bt_on" android:state_checked="true"></item>
    <item android:drawable="@drawable/heart_bt" android:state_checked="false"></item>
</selector>
```

> post_item.xml
```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:orientation="vertical">

    <ImageView
        android:id="@+id/iv_img"
        android:layout_width="match_parent"
        android:layout_height="200dp"
        android:background="#424242" />

    <RelativeLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:paddingLeft="16dp"
        android:paddingTop="8dp"
        android:paddingRight="16dp"
        android:paddingBottom="8dp">

        <CheckBox
            android:layout_centerVertical="true"
            android:id="@+id/cb_like"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:button="@drawable/like_button" />

        <!--<ImageView
            android:id="@+id/iv_like"
            android:layout_width="24dp"
            android:layout_height="24dp"
            android:background="#d50000" />-->

        <TextView
            android:id="@+id/tv_likeCount"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_centerVertical="true"
            android:layout_marginLeft="8dp"
            android:layout_toRightOf="@id/cb_like"
            android:text="1234" />

        <ImageView
            android:id="@+id/iv_share"
            android:layout_width="24dp"
            android:layout_height="24dp"
            android:layout_alignParentRight="true"
            android:background="#181818" />

    </RelativeLayout>

    <View
        android:layout_width="match_parent"
        android:layout_height="5dp"
        android:background="#0d0d0d"></View>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        android:padding="16dp">

        <TextView
            android:id="@+id/tv_userName"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="ansta_"
            android:textColor="#6200ea" />

        <TextView
            android:id="@+id/tv_postText"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginLeft="8dp"
            android:text="불꽃놀이했어요~" />

    </LinearLayout>

</LinearLayout>
```


> MainActivity.java
```java
package com.example.t717.class6_c;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.example.t717.class6_c.model.PostItem;
import com.example.t717.class6_c.recyclerview.PostAdapter;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayList<PostItem> listItem = new ArrayList<>();
        RecyclerView rvList = (RecyclerView) findViewById(R.id.rv_list);
        for (int i = 0; i < 30; i++) {
            PostItem item = new PostItem("http://cphoto.asiae.co.kr/listimglink/1/2018031618193283914_1521191973.jpg"
                    , "irene", "wow !!", 125, true);
            listItem.add(i, item);
        }
        PostAdapter adapter = new PostAdapter(this, listItem);
        rvList.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));
        rvList.setAdapter(adapter);
    }
}
```

> PostAdapter.java
```java
package com.example.t717.class6_c.recyclerview;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.example.t717.class6_c.R;
import com.example.t717.class6_c.model.PostItem;

import java.util.ArrayList;

public class PostAdapter extends RecyclerView.Adapter<PostViewHolder> {
    private Context mContext;
    private ArrayList<PostItem> postItems;

    public PostAdapter(Context mContext, ArrayList<PostItem> listItem) {
        this.mContext = mContext;
        postItems = listItem;
    }

    @NonNull
    @Override
    public PostViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View baseView = View.inflate(mContext, R.layout.post_item, null);
        PostViewHolder postViewHolder = new PostViewHolder(baseView, this);
        return postViewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull PostViewHolder postViewHolder, int position) {
        PostItem item = postItems.get(position);
        postViewHolder.tvUserName.setText(item.getUserName());
        postViewHolder.tvPostText.setText(item.getPostText());
        postViewHolder.tvLikeCount.setText(String.valueOf(item.getPostLikeCount()));
        postViewHolder.tvUserName.setText(item.getUserName());


    }

    @Override
    public int getItemCount() {
        return postItems.size();
    }

    public void onLikeClicked(int position) {
        PostItem item = postItems.get(position);
        Toast.makeText(mContext, position + " : " + item.getPostText(), Toast.LENGTH_SHORT).show();
    }
}
```

> PostViewHolder.java
```java
package com.example.t717.class6_c.recyclerview;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.t717.class6_c.R;

public class PostViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
    public CheckBox cbLike;
    public ImageView ivImg, ivShare;
    public TextView tvLikeCount, tvUserName, tvPostText;
    private PostAdapter mAdapter;

    public PostViewHolder(@NonNull View itemView, PostAdapter postAdapter) {
        super(itemView);
        mAdapter = postAdapter;
        ivImg = (ImageView) itemView.findViewById(R.id.iv_img);
        cbLike = (CheckBox) itemView.findViewById(R.id.cb_like);
        ivShare = (ImageView) itemView.findViewById(R.id.iv_share);
        tvLikeCount = (TextView) itemView.findViewById(R.id.tv_likeCount);
        tvUserName = (TextView) itemView.findViewById(R.id.tv_userName);
        tvPostText = (TextView) itemView.findViewById(R.id.tv_postText);

        cbLike.setOnClickListener(this);
        ivShare.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        int position = getAdapterPosition();

        switch (v.getId()) {
            case R.id.cb_like:
                mAdapter.onLikeClicked(position);
                break;
            case R.id.iv_share:
                break;
        }

    }
}
```
