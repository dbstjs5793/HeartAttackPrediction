# Heart Attack Prediction  
<br>
  
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
   
   <img src="https://github.com/user-attachments/assets/455b0222-e941-482e-9ca6-508791ad1dee" width="400"><br><br><br><br><br>

---  

## 프로젝트 구성<br><br>

### 1. 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. UART 통신을 통해 환자의 데이터(predict data) 전송
5. AVR 에서 test => Output 출력

    <img src="https://github.com/user-attachments/assets/74fac48d-7d01-47f6-a5b2-0ec5f9e8bd3b" width="500"><br><br><br>
### 2. 데이터셋<br>
  <img src="https://github.com/user-attachments/assets/bc21c538-321c-4158-8fa6-43ba957f733f" width="500"><br>
  <img src="https://github.com/user-attachments/assets/7b9d21ba-f7aa-4be4-9795-ba5c02cf9f4a" width="400"><br>
      <img src="https://github.com/user-attachments/assets/8a053fb7-da5e-4d59-a76c-eae31628c0f0" width="400"><br><br><br>

### 3. 커널 선택
#### A. Source Code<br>
  <img src="https://github.com/user-attachments/assets/02b2bf25-b935-48db-afc9-b8ff61c736db" width="400"><br>
- 위 코드를 커널별로 진행<br><br>
#### B. Data
<img src="https://github.com/user-attachments/assets/74a8cc4d-2934-467c-b80c-ee632aecba29" width="300"><br>
- poly kernel 에서의 정확도가 약 `0.87`로 가장 높으므로 `poly`를 사용하여 모델링한다.<br><br><br>
  
### 4. 프로젝트 코드<br>
#### A. Modeling In PyCharm
- 학습된 모델을 Micromlgen librar를 사용하여 C++로 변환한 후 저장함 -> `heart_model_poly.h`<br><br>
<img src="https://github.com/user-attachments/assets/b8bf6cdf-b794-4480-ac35-8e811ad76b69" width="400"><br><br>


- AVR 보드에 탑재하기 위해 아래 코드와 같이 C++로 변환한 코드를 C로 수정해줌 (namespace, va_arg() 등을 제거)<br><br>
<img src="https://github.com/user-attachments/assets/d6a7dce0-dfb0-45ab-b321-cf17ca1f2fc1" width="500"><br>
<img src="https://github.com/user-attachments/assets/16d4cf2e-7420-4f64-a740-04c268d0a266" width="500"><br>
    <img src="https://github.com/user-attachments/assets/fdd12eb2-4206-4ee1-a0ac-8c41722e15b3" width="500">



  
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
- Kaggle : https://www.kaggle.com/search?q=svm+in%3Adatasets
- Add jetbrain edu : https://www.jetbrains.com/pycharm-edu/
- Download pycharm : https://www.jetbrains.com/pycharm/
- Download anaconda : https://www.anaconda.com/docs/getting-started/anaconda/install
  
## 라이선스
MIT License
