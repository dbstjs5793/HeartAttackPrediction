# Heart Attack Prediction<br><br>
  
## 개요
이 프로젝트는 AVR 보드를 활용하여 심장병 여부를 예측하는 프로그램입니다.  
사용자로부터 환자의 데이터를 입력받아 심장병 여부를 진단합니다.
<br><br><br>

## 기술 스택
- **AVR 보드**
- **VSPE**와 **PuTTY**를 사용한 **UART 통신**
- **Scikit-learn**, **PyTorch**를 활용한 모델 구축 및 성능 최적화
<br><br><br>

## Design method
<img src="https://github.com/user-attachments/assets/153e74a2-2aa6-4072-95fe-a22f9e3e4898" width="300"><br>

 - 본 프로젝트에서는 method2를 사용하므로 사용할 데이터셋이 Libsvm 포멧이면 sklearn-svm의 포멧으로 변환해줘야함
 - 페이지 하단의 `method2 기본 예제`를 참고하여 프로젝트를 수행함
   
   <img src="https://github.com/user-attachments/assets/455b0222-e941-482e-9ca6-508791ad1dee" width="400"><br><br><br><br><br>

---  

## 프로젝트 구성<br><br>

### 1. 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. UART 통신을 통해 환자의 데이터(predict data) 전송
5. AVR 에서 test => Output 출력<br>
<img src="https://github.com/user-attachments/assets/74fac48d-7d01-47f6-a5b2-0ec5f9e8bd3b" width="500"><br><br><br>

### 2. 데이터셋<br>
- **데이터셋 구성**<br> `heart.csv`
<img src="https://github.com/user-attachments/assets/bc21c538-321c-4158-8fa6-43ba957f733f" width="500"><br>
- **label**<br>
<img src="https://github.com/user-attachments/assets/7b9d21ba-f7aa-4be4-9795-ba5c02cf9f4a" width="400"><br><br>
- **value**<br>
<img src="https://github.com/user-attachments/assets/8a053fb7-da5e-4d59-a76c-eae31628c0f0" width="400"><br>
    `[1]`<br><br><br>

### 3. 커널 선택
#### A. Source Code<br>
- 아래 코드를 커널별로 진행<br>
  <img src="https://github.com/user-attachments/assets/02b2bf25-b935-48db-afc9-b8ff61c736db" width="400"><br>
#### B. Data
- poly kernel 에서의 정확도가 약 `0.87`로 가장 높으므로 `poly`를 사용하여 모델링한다.<br>
<img src="https://github.com/user-attachments/assets/74a8cc4d-2934-467c-b80c-ee632aecba29" width="300"><br><br><br>
  
### 4. 프로젝트 코드<br>
#### 4-1. Modeling In PyCharm<br>
- `PyCharm_code.txt` : 데이터셋을 통해 학습된 모델을 Micromlgen librar를 사용하여 C++로 변환한 후 저장함 -> `heart_model_poly.h`<br><br>
<img src="https://github.com/user-attachments/assets/b8bf6cdf-b794-4480-ac35-8e811ad76b69" width="400"><br><br>
#### 4-2. convert to C code<br>
- `h파일 to C함수.txt` : AVR 보드에 탑재하기 위해 아래 코드와 같이 C++로 변환한 코드를 C로 수정해줌 (namespace, va_arg() 등을 제거)<br><br>
<img src="https://github.com/user-attachments/assets/d6a7dce0-dfb0-45ab-b321-cf17ca1f2fc1" width="500"><br>
<img src="https://github.com/user-attachments/assets/16d4cf2e-7420-4f64-a740-04c268d0a266" width="500"><br>
    <img src="https://github.com/user-attachments/assets/fdd12eb2-4206-4ee1-a0ac-8c41722e15b3" width="500"><br><br><br>

#### 4-3. AVR 보드에 탑재<br>
- 코드<br>
<img src="https://github.com/user-attachments/assets/b849a98a-6761-4d5c-abb7-77cb16aeedae" width="400"><br>
↳ ...위 4-2에서 C로 변환해준 함수 이하 생략<br><br><br>
<img src="https://github.com/user-attachments/assets/058cb28e-2149-482f-a8d5-c1bf2a84db3b" width="350"><br>
`[2]`<br><br>
<img src="https://github.com/user-attachments/assets/12eb35ed-0464-49a7-bb35-1e26ad1b3629" width="400"><br><br>
<img src="https://github.com/user-attachments/assets/887b6b6a-ae7c-4a66-8157-3567369a9052" width="450"><br><br>
<img src="https://github.com/user-attachments/assets/020b94b3-c91d-4537-b7ad-3b06abbad236" width="500"><br>
<img src="https://github.com/user-attachments/assets/17e9bd19-daf2-4d4f-8aa5-59a217c2bdbd" width="500"><br>
<img src="https://github.com/user-attachments/assets/019d8fba-1c9d-43c8-88b0-9b34bd4dd0ae" width="400"><br><br><br>

### 5. 결과<br>
#### 5-1. Data<br>
- 입력 데이터 : `test용 data.txt`
-  Input data ( label 0 ) = `55`, `1`, `0`, `132`, `353`, `0`, `1`, `132`, `1`, `1.2(반올림->1)`, `1`, `1`, `3`<br>
  -> Led Blink, siren sound, FND ‘risk’, PuTTY에 해당 문구가 출력되는 것을 확인할 수 있음<br>
   <img src="https://github.com/user-attachments/assets/c10c7b7d-bdf5-45c6-a971-f5beba65aeab" width="500">
- Input data ( label 1 ) = `45`, `0`, `0`, `138`, `236`, `0`, `0`, `152`, `1`, `0.2(반올림->0)`, `1`, `0`, `2`<br>
  -> Led ON, safe sound, FND ‘safe’, PuTTY에 해당 문구가 출력되는 것을 확인할 수 있음<br>
  <img src="https://github.com/user-attachments/assets/a5e051db-1dff-4653-bd67-a2bad8e35f04" width="500"><br>
  <  좌 - PuTTY 화면   /  우 - AVR 보드  ><br>
#### 5-2. Discussion <br>
- data 파일을 보면, 최대 자릿수가 100의자리이므로 PuTTY에서 모든 데이터 값을 3자리로 
입력받도록 프로그램을 작성하였다.
- 음계는 ‘주기=1/진동수’ 임을 활용하여 구현하였다. (ms이므로 1000/주파수/2)<br>

#### 5-3. 동작 영상
- https://www.notion.so/b236ab536250432cad836ede5af3bb2a?pvs=4<br><br>


### 6. References<br>
[1] UCI, “Heart Disease Data Set”, UCI Machine Learning Repository: Heart Disease Data Set , 
(2021. 06. 10)<br>
[2] atmega128 datasheet<br>
<img src="https://github.com/user-attachments/assets/73f02a5b-dba7-4bc8-bb77-bd9636538d24" width="300"><br><br><br><br>





  
## method2 기본 예제

### 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. Visual Studio 에서 test => Output : string
5. AVR 에서 test => Output : led

### 예제 코드
- `convert_svm.py` : 학습된 머신러닝 모델(SVM)을 C 코드로 변환하여 저장
  
  <img src="https://github.com/user-attachments/assets/02391f7a-9b74-4580-b860-b873065ee487" width="500">

- `model_linear.h` `model_poly.h` `model_rbf.h` `model_sigmoid.h` :  
  convert_svm.py를 통해 저장된 C++ 코드의 모델, 이를 C로 수정해주어야함

  <img src="https://github.com/user-attachments/assets/6f1da94a-8303-4720-adda-5ca8a1f7d413" width="500">
  <img src="https://github.com/user-attachments/assets/aded42e5-580d-4d47-bb60-73768f60edcc" width="500">

  
- `svm_test_VS.c` :  Visual Studio 에서 test하는 코드
  <img src="https://github.com/user-attachments/assets/3a40dd4e-66dc-473e-a7d4-9aa516ce5ab8" width="500">

- `svm_avr_linear.c` `svm_avr_poly.c` `svm_avr_rab.c` `svm_avr_sig.c` : AVR 에서 test하는 코드
  <img src="https://github.com/user-attachments/assets/5e90537e-8ddb-42bc-8c3b-b79d14566197" width="500">

  
### 참고 사이트
- Kaggle : https://archive.ics.uci.edu/dataset/45/heart+disease
- Add jetbrain edu : https://www.jetbrains.com/pycharm-edu/
- Download pycharm : https://www.jetbrains.com/pycharm/
- Download anaconda : https://www.anaconda.com/docs/getting-started/anaconda/install<br><br>
  
## 라이선스
MIT License
