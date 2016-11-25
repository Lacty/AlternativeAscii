
## GUI docment
GUIはシングルトンクラスで    
各機能のguiを管理する為に使用します    

``GUI* get()``
>インスタンスを返します    
>``GUI::get()->draw()``のように使用します    

``void setup();``
>GUIのセットアップと    
>インスタンスの確保を行う為に使用します   
>一度行えばいいので基本使いません

``void draw()``
>guiの描画をします

``void add(const string& name, ofxPanel& panel)``
>GUIクラスにofxPanelを追加し管理させます    
>``GUI::get()->add("Player", gui);``    
>player.cpp Player::setupGui() 参照
