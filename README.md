# Heart Attack Prediction  

  
## 개요
이 프로젝트는 AVR 보드를 활용하여 심장병 여부를 예측하는 프로그램입니다.  
사용자로부터 환자의 데이터를 입력받아 심장병 여부를 진단합니다.

## Design method
![image](https://github.com/user-attachments/assets/153e74a2-2aa6-4072-95fe-a22f9e3e4898)  

 - 본 프로젝트에서는 method2를 사용하므로 사용할 데이터셋이 Libsvm 포멧이면 sklearn-svm의 포멧으로 변환해줘야함
 - AVR보드와 UART 통신을 하기 위해 C++ code로 convert한 후, C로 수정해줘야함

## 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. Visual Studio 에서 test => Output : string
5. AVR 에서 test => Output : led

## 기술 스택
- **AVR 보드**
- **VSPE**와 **PuTTY**를 사용한 **UART 통신**
- **Scikit-learn**, **PyTorch**를 활용한 모델 구축 및 성능 최적화

## 실행 방법
1. Kaggle에서 데이터셋을 다운로드
2. Scikit-learn 라이브러리를 활용하여 SVM 모델 생성
3. UART 통신을 통해 예
4. AVR 보드를 연결하고, 통신 프로그램을 실행하여 진단 결과를 확인합니다.

## 프로젝트 구성
- `convert_svm.py` : 학습된 머신러닝 모델(SVM)을 C 코드로 변환하고 저장 (기본 예제 코드)
  
  ![image](https://github.com/user-attachments/assets/02391f7a-9b74-4580-b860-b873065ee487)

- `convert_svm_numpy.py` : 학습된 머신러닝 모델(SVM)을 C 코드로 변환하고 저장 (프로젝트에서 사용한 코드)
- 'model_linear.h' :

    ![image](https://github.com/user-attachments/assets/6f1da94a-8303-4720-adda-5ca8a1f7d413)

- `heart_model_poly.h`: 심장병 예측 모델
- `data/`: Kaggle 데이터셋
- `README.md`: 프로젝트 설명

### 참고 사이트
- Kaggle : https://www.kaggle.com/search?q=svm+in%3Adatasets
- Add jetbrain edu : https://www.jetbrains.com/pycharm-edu/
- Download pycharm : https://www.jetbrains.com/pycharm/
- Download anaconda : https://www.anaconda.com/docs/getting-started/anaconda/install
  
## 라이선스
MIT License
