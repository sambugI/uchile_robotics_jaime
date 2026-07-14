#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "jaime_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__jaime_interfaces__srv__IsReady_Request() -> *const std::ffi::c_void;
}

#[link(name = "jaime_interfaces__rosidl_generator_c")]
extern "C" {
    fn jaime_interfaces__srv__IsReady_Request__init(msg: *mut IsReady_Request) -> bool;
    fn jaime_interfaces__srv__IsReady_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsReady_Request>, size: usize) -> bool;
    fn jaime_interfaces__srv__IsReady_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsReady_Request>);
    fn jaime_interfaces__srv__IsReady_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsReady_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsReady_Request>) -> bool;
}

// Corresponds to jaime_interfaces__srv__IsReady_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsReady_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsReady_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !jaime_interfaces__srv__IsReady_Request__init(&mut msg as *mut _) {
        panic!("Call to jaime_interfaces__srv__IsReady_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsReady_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsReady_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsReady_Request where Self: Sized {
  const TYPE_NAME: &'static str = "jaime_interfaces/srv/IsReady_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__jaime_interfaces__srv__IsReady_Request() }
  }
}


#[link(name = "jaime_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__jaime_interfaces__srv__IsReady_Response() -> *const std::ffi::c_void;
}

#[link(name = "jaime_interfaces__rosidl_generator_c")]
extern "C" {
    fn jaime_interfaces__srv__IsReady_Response__init(msg: *mut IsReady_Response) -> bool;
    fn jaime_interfaces__srv__IsReady_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsReady_Response>, size: usize) -> bool;
    fn jaime_interfaces__srv__IsReady_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsReady_Response>);
    fn jaime_interfaces__srv__IsReady_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsReady_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsReady_Response>) -> bool;
}

// Corresponds to jaime_interfaces__srv__IsReady_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsReady_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub ready: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for IsReady_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !jaime_interfaces__srv__IsReady_Response__init(&mut msg as *mut _) {
        panic!("Call to jaime_interfaces__srv__IsReady_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsReady_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { jaime_interfaces__srv__IsReady_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsReady_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsReady_Response where Self: Sized {
  const TYPE_NAME: &'static str = "jaime_interfaces/srv/IsReady_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__jaime_interfaces__srv__IsReady_Response() }
  }
}






#[link(name = "jaime_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__jaime_interfaces__srv__IsReady() -> *const std::ffi::c_void;
}

// Corresponds to jaime_interfaces__srv__IsReady
#[allow(missing_docs, non_camel_case_types)]
pub struct IsReady;

impl rosidl_runtime_rs::Service for IsReady {
    type Request = IsReady_Request;
    type Response = IsReady_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__jaime_interfaces__srv__IsReady() }
    }
}


