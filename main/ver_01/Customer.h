class Customer {
    protected:
      char name[100];
      char address[100];
      char phone[12];
      char from_date[20];
      char to_date[20];
      float payment_advance;
      int booking_id;
    public:
          Customer();
          ~Customer();
          void setName(char&);
          void setAddress(char&);
          void setPhone(char&);
          void setFromDate(char&);
          void setToDate(char&);
          void setPaymentAdvance(float);
          void setBookingId(int);
          char getName() const;
          char getAddress() const;
          char getPhone() const;
          char getFromDate() const;
          char getToDate() const;
          float getPaymentAdvance() const;
          int getBookingId() const;
};
